    /**************filename: Server.cpp**************** 
     该程序通过标准socket实现简单Http服务器 
     运行该服务器可以通过浏览器访问服务器目录下的 
     Html文件和jpg图片 完成初步的Http服务器功能 
    ***************************************************/  
    #include <stdarg.h>  
    #include <errno.h>  
    #include <stdio.h>  
    #include <fcntl.h>  
    #include <unistd.h>  
    #include <string.h>  
    #include <time.h>  
    #include <sys/types.h>  
    #include <sys/stat.h>  
    #include <dirent.h>  
    #include <errno.h>  
    #include <netinet/in.h>  
    #include <sys/socket.h>  
    #include <resolv.h>  
    #include <arpa/inet.h>  
    #include <stdlib.h>  
    #include <signal.h>  
    #include <getopt.h>  
    #include <iostream>
	#include <string>

    int sendall(int s, char *buf, int *len);
    void wrong_req(int sock);
    int not_exit(char* arguments);
	void file_not_found(char* arguments, int sock, const char *default_page);
	void send_header(int send_to, char* content_type);
    char* file_type(char* arg);
	void send_file(char* arguments, int sock);
    void handle_req(char* request, int client_sock);
	int make_server_socket();

	using namespace std;
    #define SERVER_PORT 8089        // 自定义的服务端口  
    #define HOSTLEN 256             // 主机名长度  
    #define BACKLOG 10              // 同时等待的连接个数  
      
    /************************************** 
     该方法包装了send() 
     通过该方法发送数据 能够全部发出 
     没有遗漏 
    **************************************/  
    int sendall(int s, char *buf, int *len)  
    {  
        int total = 0;              // 已经发送字节数  
        int bytesleft = *len;       // 还剩余多少字节  
        int n;  
        while(total < *len)  
        {  
            n = send(s, buf + total, bytesleft, 0);  
			
			cout<<buf + total<<endl;

            if (n == -1)  
            {  
                break;  
            }  
            total += n;  
            bytesleft -= n;  
        }  
        *len = total;               // 返回实际发送出去的字节数  
        return n==-1 ? -1 : 0;      // 成功发送返回0 失败-1  
    }  
      
    /************************************** 
     该方法处理错误请求 
     并向客户端发送错误信息 
    **************************************/  
    void wrong_req(int sock) {  
        char error_head[] = "HTTP/1.0 501 Not Implemented\r\n"; // 输出501错误  
        int len = strlen(error_head);  
        if (sendall(sock, error_head, &len) == -1)      // 向客户发送  
        {  
            printf("Sending failed!");  
            return;  
        }  
      
        char error_type[] = "Content-type: text/plain\r\n";  
        len = strlen(error_type);  
        if (sendall(sock, error_type, &len) == -1)  
        {  
            printf("Sending failed!");  
            return;  
        }  
      
        char error_end[] = "\r\n";  
        len = strlen(error_end);  
        if (sendall(sock, error_end, &len) == -1)  
        {  
            printf("Sending failed!");  
            return;  
        }  
      
        char prompt_info[] = "The command is not yet completed\r\n";  
        len = strlen(prompt_info);  
        if (sendall(sock, prompt_info, &len) == -1)  
        {  
            printf("Sending failed!");  
            return;  
        }  
    }  
      
    /********************************** 
     该方法判断用户请求的文件是否存在 
     不存在返回非0 存在返回0 
    ***********************************/  
    int not_exit(char* arguments)  
    {  
        struct stat dir_info;  
        //return (stat(arguments, &dir_info) == -1);  
        return access(arguments, 0);  
    }  
      
    /************************************* 
     所请求的文件不存在 
    *************************************/  
    void file_not_found(char* arguments, int sock, const char *default_page)  
    {  
		//if(default_page == NULL){			
			char error_head[] = "HTTP/1.0 404 Not Found\r\n";    // 构造404错误head  
			int len = strlen(error_head);  
		
			if (sendall(sock, error_head, &len) == -1)          // 向客户端发送  
		    {  
				 printf("Sending error!");  
				 return;  
			}  
      
			char error_type[] = "Content-type: text/plain\r\n";  
			len = strlen(error_type);  
			if (sendall(sock, error_type, &len) == -1)  
			{  
				printf("Sending error!");  
				return;  
			}  
      
			char error_end[] = "\r\n";  
			len = strlen(error_end);  
			if (sendall(sock, error_end, &len) == -1)  
			{  
				printf("Sending error!");  
				return;  
			}  
      
			char prompt_info[50] = "Not found:  ";  
			strcat(prompt_info, arguments);  
			len = strlen(prompt_info);  
			if (sendall(sock, prompt_info, &len) == -1)         // 输出未找到的文件  
			{  
				printf("Sending error!");
				//send_file("./index.html",sock);
				return;  
			}
		//}else{
		//	send_file(default_page, sock);
		//	return;
	//	}
    }  
      
    /************************************* 
     发送Http协议头部信息 
     其中包括响应类型和Content Type 
    *************************************/  
    void send_header(int send_to, char* content_type)  
    {  
        char head[] = "HTTP/1.0 200 OK\r\n";     // 正确的头部信息  
        int len = strlen(head);  
        if (sendall(send_to, head, &len) == -1) // 向连接的客户端发送数据  
        {  
            printf("Sending error");  
            return;  
        }  
      
        if (content_type)                       // content_type不为空  
        {  
            //char temp_1[125] = "Content-Disposition: attachment\r\nContent-type: "; // 准备好要连接的字串  
			char temp_1[125] = "Content-type: ";
            //char temp_1[125] = "Content-type: ";  // 准备好要连接的字串  
            strcat(temp_1, content_type);       // 构造content_type  
            strcat(temp_1, "\r\n");  
            len = strlen(temp_1);  
            if (sendall(send_to, temp_1, &len) == -1)  
            {  
                printf("Sending error!");  
                return;  
            }  
        }  
    }  
      
    /*********************************** 
     取得用户所请求的文件类型 
     即文件后缀 (.html .jpg .gif) 
    ************************************/  
    char* file_type(char* arg)  
    {  
        char * temp;                            // 临时字符串指针  
        if ((temp = strrchr(arg, '.')) != NULL) // 取得后缀  
        {  
            return temp + 1;  
        }  
        return NULL;                              // 如果请求的文件名中没有. 则返回空串  
    }  
      
    /************************************* 
     该方法为程序核心 
     负责真正发送文件 如*.html *.jpg等 
    *************************************/  
    void send_file(char* arguments, int sock)  
    {  
        char* extension = file_type(arguments); // 获得文件后缀名  
        //char* content_type = "text/plain";        // 初始化type='text/plain'  
        char content_type[100];
		snprintf(content_type, sizeof(content_type), "application/octet-stream");  
        FILE* read_from;                        // 本地文件指针从该文件中读取.html .jpg等  
        int readed = -1, file_len = 0;          // 每次读得的字节数、文件总长度  
        char read_buf[256] = {0};               // 读文件时的字节缓存数组  
        char *file_buf = NULL;                  // 文件内容  
        char *szTmp = NULL;  
        int tmp_len = 0;  
        static char num = 0;  
      
        printf("send_file\n");  
        if (strcmp(extension, "html") == 0)     // 发送内容为html  
        {  
            // content_type = "text/html";  
			snprintf(content_type, sizeof(content_type), "text/html");  
        }  
      
        if (strcmp(extension, "gif") == 0)      // 发送内容为gif  
        {  
            // content_type = "image/gif";  
			snprintf(content_type, sizeof(content_type), "image/gif");  
        }  
      
        if (strcmp(extension, "jpg") == 0)      // 发送内容为jpg  
        {  
            // content_type = "image/jpg";  
			snprintf(content_type, sizeof(content_type), "image/jpg");  
        }  
		if(strcmp(extension, "ico") == 0){
			// content_type = "image/x-icon";
			snprintf(content_type, sizeof(content_type), "image/x-icon");  
		} 
        read_from = fopen(arguments, "rb");     // 打开用户指定的文件准备读取  
        if (read_from != NULL)                  // 指针不为空  
        {  
            fseek(read_from, 0, SEEK_SET);  
            fseek(read_from, 0, SEEK_END);        
            file_len = ftell(read_from);  
            file_buf = (char *)malloc(file_len + 1);  
            if (file_buf == NULL)  
            {  
                printf("malloc error!");  
            }  
            memset(file_buf, 0, file_len + 1);  
              
            szTmp = file_buf;  
            fseek(read_from, 0, SEEK_SET);  
            while (!feof(read_from))  
            {  
                memset(read_buf, 0, sizeof (read_buf));  
                readed = fread(read_buf, 1, sizeof(read_buf), read_from);  
                if (readed <= 0)  
                {  
                    continue;  
                }  
                memcpy(szTmp, read_buf, readed);  
                szTmp += readed;  
                tmp_len += readed;  
            }  
            fclose(read_from);  
              
            printf("file_len = %d, tmp_len = %d\n", file_len, tmp_len);  
              
            send_header(sock, content_type);    // 发送协议头  
			cout<<content_type<<endl;
            memset(read_buf, 0, sizeof (read_buf));  
            sprintf(read_buf, "Content-Length: %d\r\n", file_len);  
            tmp_len = strlen(read_buf);  
            if (sendall(sock, read_buf, &tmp_len) == -1)  
            {  
                printf("Sending error!");  
                return;  
            }  
            send(sock, "\r\n", 2, 0);           // 再加一个"\r\n" 不能缺少 格式要求  
              
            if (num != 0)  
            {  
                //printf("no send because num = %d\n", num);  
               // return;  
            }  
              
            if (sendall(sock, file_buf, &file_len) == -1)// 发送数据  
            {  
                printf("Sending file_buf error!\n");   // 出现发送错误显示到控制台 继续发送  
            }  
            else  
            {  
                num++;  
            }  
        }  
    }  
      
    /*********************************** 
     解析并处理用户请求 
    ***********************************/  
    void handle_req(char* request, int client_sock)  
    {  
        char command[BUFSIZ];                   // 保存解析到的命令字段 GET PUT  
        char arguments[BUFSIZ];                 // 保存解析到的请求的文件  
      
        /* 
        * 在用户请求前加上当前目录符号 
        */  
        strcpy(arguments, "./");                // 注意该符号在不同操作系统的区别  
          
        printf("request = %s\n", request);  
      
        /* 
        * 解析请求 
        */  
        if (sscanf(request, "%s /%s", command, arguments + 2) != 2)  
        {  
            return;                             // 解析出错在返回  
        }  
      
        //printf("handle_cmd:    %s\n",command);  // 向控制台输出此时的命令  
        //printf("handle_path:   %s\n",arguments);// 向控制台输出此时的请求路径  
      
        if (strcmp(command, "GET") != 0)        // 请求命令格式是否正确  
        {  
            wrong_req(client_sock);  
            return;  
        }  
      
        cout<<"arguments:"<<arguments<<endl;
        if (not_exit(arguments))                // 请求的文件是否存在  
        {  
            printf("not exit\n");  
            file_not_found(arguments, client_sock,"./index.html");
            return;  
        }  
        cout<<"arguments:"<<arguments<<endl;
        send_file(arguments, client_sock);      // 命令格式及请求路径正确则发送数据  
      
        return;  
    }  
      
    /************************************* 
     该方法构造服务器端的SOCKET 
     返回构造好的socket描述符 
    *************************************/  
    int make_server_socket()  
    {  
        struct sockaddr_in server_addr;         // 服务器地址结构体  
        int tempSockId;                         // 临时存储socket描述符  
        tempSockId = socket(AF_INET, SOCK_STREAM, 0);  
      
        if (tempSockId == -1)                   // 如果返回值为－1 则出错  
        {  
            return -1;  
        }  
      
        /* 
        * 填充服务器连接信息 
        */  
        server_addr.sin_family = AF_INET;  
        server_addr.sin_port = htons(SERVER_PORT);  
        server_addr.sin_addr.s_addr = INADDR_ANY;//inet_addr("10.2.3.51");  //本地地址  
        memset(&(server_addr.sin_zero), '\0', 8);  
      
        // 绑定服务如果出错 则返回－1  
        if (bind(tempSockId, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)  
        {  
            printf("bind error!\n");  
            return -1;  
        }  
      
        if (listen(tempSockId, BACKLOG) == -1 ) // 开始监听  
        {  
            printf("listen error!\n");  
            return -1;  
        }  
      
        return tempSockId;                      // 返回取得的SOCKET  
    }  
      
    /*********************** 
     主函数main() 
     程序入口 
    ***********************/  
    int main(int argc, char * argv[])  
    {  
        //printf("My web server started...\n");  
      
        int server_socket;                      // 服务器的socket  
        int acc_socket;                         // 接收到的用户连接的socket  
        int sock_size = sizeof(struct sockaddr_in);  
        struct sockaddr_in user_socket;         // 客户连接信息  
        server_socket = make_server_socket();   // 创建服务器端的socket  
      
        if (server_socket == -1)                // 创建socket出错  
        {  
            printf("Server exception!\n");  
            exit(2);  
        }  
          
       // printf("server_socket = %d\n", server_socket);  
      
        /* 
        * 主循环 
        */
		pid_t pid;
        while (1)  
        {  
            //acc_socket = accept(server_socket, (struct sockaddr *)&user_socket, &sock_size); // 接收连接  
			acc_socket = accept(server_socket, NULL, NULL); // 接收连接  
            // printf("acc_socket = %d\n", acc_socket);     // use test  
      
            /* 
            * 读取客户请求 
            */  
            if((pid = fork()) == 0){
				int numbytes;  
				char buf[100];  
				if ((numbytes = recv(acc_socket, buf, 99, 0)) == -1)  
				{  
					perror("recv");  
					exit(1);  
				}  
      
            //printf("buf ... %s", buf);        // use test  
      
            /* 
            * 处理用户请求 
            */  //exit(0);
				handle_req(buf, acc_socket); 
				exit(10);
				//if(pid > 0){
				//	kill(getpid(),SIGALERM);
				//fork();
				//}
			}
		}  
    }  
