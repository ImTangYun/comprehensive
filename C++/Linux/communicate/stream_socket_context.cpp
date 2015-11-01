#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include "task_queue.h"
#include "stream_socket_context.h"
#include "communicate_loop.h"
#include "packet.h"
int StreamSocketContext::Init()
{
    if (ip_ != NULL) {
        printf("fd: %d had been inited before\n", fd_);
        return 0;
    }
    if (ParseIpPort() < 0) {
        printf("parse ip and port failed!\n");
        return -1;
    }
    printf("parse ip and port over, ip:%s, port:%d\n", ip_, port_);
    fd_ = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_);
    inet_pton(AF_INET, ip_, &servaddr.sin_addr);

    printf("connectiong....\n");
    if (connect(fd_, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        return -1;
    }

    printf("return code of AddEvent is %d\n",
            communicate_loop_->AddEvent(this, true, true));
    return 0;
}

int StreamSocketContext::ParseIpPort()
{
    ip_ = new char[16];
    int i = 0;
    for (; i < ip_port_.length(); ++i) {
        if (ip_port_[i] == ':') break;
        ip_[i] = ip_port_[i];
    }
    ip_[i] = '\0';
    char buff[10];
    int count = 0;
    ++i;
    for (; i < ip_port_.length(); ++i) {
        buff[count] = ip_port_[i];
        ++count;
    }
    buff[count] = '\0';
    port_ = atoi(buff);
    return 0;
}

int StreamSocketContext::AsyncSendPacket(Packet* packet)
{
    if (packet == NULL) return -1;
    packet_queue_->Push(packet);
    return 0;
}

int StreamSocketContext::HandleOutput()
{
    printf("HandleOutput()\n");
    Packet* packet = packet_queue_->Pop();
    int32_t channel_id = packet->channel_id();
    int32_t data_length = packet->data_length();
    char* data = packet->data();
    int32_t total_length = sizeof(channel_id) +
        sizeof(data_length) + data_length;
    char* buff = new char[sizeof(channel_id) +
        sizeof(data_length) + data_length + 1];
    int32_t* buff_int = reinterpret_cast<int32_t*>(buff);
    buff_int[0] = channel_id;
    buff_int[1] = data_length;
    char* buff_data = buff + sizeof(channel_id) + sizeof(data_length);
    memcpy(buff_data, data, data_length);
    Send(buff_data, total_length);
    return 0;
}

int StreamSocketContext::Send(char* data, int32_t length)
{
    int sent_length = 0;
    while (true) {
        int ret = send(fd_, data + sent_length, length - sent_length, 0);
        if (ret < 0) {
            printf("sending error!\n");
            return ret;
        }
        sent_length += ret;
        if (sent_length == length) {
            return 0;
        }
    }
}

int StreamSocketContext::HandleInput()
{
    return 0;
}
