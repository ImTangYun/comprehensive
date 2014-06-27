#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#define MAXLINE 4096

void setnonblocking(int sock)
{
	int opts;
	opts = fcntl(sock, F_GETFL);
	if (opts < 0) {
		perror("set nonblocking\n");
		exit(1);
	}
	opts = opts|O_NONBLOCK;
	if (fcntl(sock, F_GETFL, opts) < 0) {
		perror("set nonblocking2\n");
		exit(1);
	}
}

int32_t main()
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;

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
	bool bDontLinger = false;
	setsockopt(listenfd,SOL_SOCKET,SO_LINGER,(const char*)&bDontLinger,sizeof(bool));
	// pthread_create(&pid, NULL, thr_1, NULL);

	int efd;
	int nfds;
	efd = epoll_create(256);
	struct epoll_event ev, events[20];
	setnonblocking(listenfd);
	ev.data.fd = listenfd;
	ev.events = EPOLLIN|EPOLLET;
	// ev.events = EPOLLIN;
	epoll_ctl(efd, EPOLL_CTL_ADD, listenfd, &ev);
	while (true) {
		nfds = epoll_wait(efd, events, 20, 500);

		for (int i = 0; i < nfds; ++i) {
			if (events[i].data.fd == listenfd) {
				connfd = accept(listenfd, NULL, NULL);
				if (connfd < 0) {
					perror("accept error\n");
					exit(1);
				}
				setnonblocking(connfd);
				ev.data.fd = connfd;
				ev.events = EPOLLIN|EPOLLET;
				// ev.events = EPOLLET;
				epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &ev);
			} else if (events[i].events&EPOLLIN) {
				char buff[1000];
				int ret = recv(events[i].data.fd, buff, 1000, 0);
				if (ret < 0) {
					perror("recv error\n");
					exit(1);
				}
				buff[ret] = '\0';
				printf("epoll mode received:%s\n", buff);
			}
		}
	}

	close(listenfd);
	return 0;
}

