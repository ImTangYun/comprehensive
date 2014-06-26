#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include <pthread.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include <arpa/inet.h>

#define MAXLINE 4096
pthread_t pid;

void *thr(void *args)
{
    printf("my pid is: %d\n", pid);
    int connfd = *(int*)args;
    char    buff[4096];
    int32_t n = recv(connfd, buff, MAXLINE, 0);
    buff[n] = '\0';
    struct sockaddr_in sa;
    socklen_t len = static_cast<socklen_t>(sizeof(sa));
    if(!getpeername(connfd, (struct sockaddr *)&sa, &len))
    {
        printf( "IP:%s \n", inet_ntoa(sa.sin_addr));
        printf( "PORT:%d \n", ntohs(sa.sin_port));
    }
    printf("recv msg from client: %s\n", buff);
    close(connfd);
    pthread_exit(0);
}

int32_t main()
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    int32_t n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }

    if( listen(listenfd, 10) == -1){
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }
    printf("======waiting for client's request======\n");
	fd_set fread, fwrite, ferror;
	struct timeval timeout;
	int count = 0;
	bool bDontLinger = false;
	setsockopt(listenfd,SOL_SOCKET,SO_LINGER,(const char*)&bDontLinger,sizeof(bool));
    while(1){
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;
		FD_ZERO(&fread);
		FD_ZERO(&fread);
		FD_SET(listenfd, &fread);
		// printf("%d\n", count);
		switch(select(listenfd + 1, &fread, &fwrite, NULL, &timeout)) {
			case -1:
				printf("error\n");
				break;
			case 0:
				// printf("--\n");
				break;
			default:
				printf("connect ok!\n");
				if (FD_ISSET(listenfd, &fread)) {
					if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
						printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
						continue;
					}
					pthread_create(&pid, NULL, thr, &connfd);
				}
		}

        /*n = recv(connfd, buff, MAXLINE, 0);
        buff[n] = '\0';
        printf("recv msg from client: %s\n", buff);
        close(connfd);*/
    }

    close(listenfd);
    return 0;
}

