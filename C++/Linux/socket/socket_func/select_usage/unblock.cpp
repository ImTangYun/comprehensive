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
#include <set>
using std::set;

#define MAXLINE 4096
pthread_t pid;
set<int> fds;

// polling the connectings
void *thr_1(void *args)
{
	char buff[MAXLINE];
	while (true) {
		while (fds.size() <= 0) {
			usleep(10000);
		}
		for (set<int>::iterator iter = fds.begin();
				iter != fds.end(); ++iter) {
			int32_t n = recv(*iter, buff, MAXLINE, MSG_DONTWAIT);
			buff[n] = '\0';
			if (n > 0) printf("received:\n\n%s\n\n", buff);
			usleep(10000/(fds.size()));
		}
	}
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
	pthread_create(&pid, NULL, thr_1, NULL);
    while(1){
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;
		FD_ZERO(&fread);
		FD_ZERO(&fwrite);
		FD_SET(listenfd, &fread);
		FD_SET(listenfd, &fwrite);
		switch(int ret = select(listenfd + 1, &fread, &fwrite, NULL, &timeout)) {
			case -1:
				printf("error\n");
				break;
			case 0:
				// printf("timeout...\n");
				break;
			default:
				for (int i = 0; i < ret; ++i)
					printf("%lu connect ok!\n", fread.fds_bits[0]);
				if (FD_ISSET(listenfd, &fread)) {
					if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
						printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
						continue;
					}
					fds.insert(connfd);
					printf("%d connect ok!--\n", connfd);
				} else if (FD_ISSET(listenfd, &fwrite)) {
					// writing....
				} else {
					// do some other thing
				}
		}
    }
    close(listenfd);
    return 0;
}

