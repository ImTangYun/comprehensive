#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include "task_queue.h"
#include "stream_socket_context.h"
#include "communicate_loop.h"
#include "packet.h"
#include "net_handler.h"
#include "net_machine.h"
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
    SetNonblocking(fd_);

    printf("return code of AddEvent is %d\n",
            net_machine_->communicate_loop()->AddEvent(this, true, true));
    return 0;
}

int StreamSocketContext::AsyncSendPacket(Packet* packet)
{
    if (packet == NULL) return -1;
    packet_queue_->Push(packet);
    communicate_loop_->SetEvent(this, true, true);
    return 0;
}

int StreamSocketContext::HandleOutput()
{
    Packet* packet = packet_queue_->Pop();
    uint32_t channel_id = htonl(packet->channel_id());
    uint32_t data_length = htonl(packet->data_length());
    printf("sending channel_id:%d, data_length:%d\n", channel_id, packet->data_length());
    char* data = packet->data();
    uint32_t total_length = sizeof(channel_id) +
        sizeof(data_length) + packet->data_length();
    char* buff = new char[sizeof(channel_id) +
        sizeof(data_length) + data_length + 1];
    uint32_t* buff_int = reinterpret_cast<uint32_t*>(buff);
    buff_int[0] = channel_id;
    buff_int[1] = data_length;
    char* buff_data = buff + sizeof(channel_id) + sizeof(data_length);
    memcpy(buff_data, data, packet->data_length());
    delete packet;
    Send(buff, total_length);
    delete [] buff;
    return 0;
}

int StreamSocketContext::Send(char* data, uint32_t length)
{
    uint32_t sent_length = 0;
    while (true) {
        uint32_t ret = send(fd_, data + sent_length, length - sent_length, 0);
        if (ret < 0) {
            printf("sending error!\n");
            return ret;
        }
        sent_length += ret;
        if (sent_length == length) {
            return 0;
        }
        printf("sent length: %u\n", sent_length);
    }
}

int StreamSocketContext::HandleInput()
{
    int received_length = 0;
    while (true) {
        int ret = recv(fd_, recv_buffer_ + received_length,
                recv_buffer_length_ - received_length, 0);
        if (ret <= 0) {
            break;
        }
        received_length += ret;
        AdjustBuffer(received_length);
    }
    uint32_t* head = reinterpret_cast<uint32_t*>(recv_buffer_);
    uint32_t channel_id = ntohl(head[0]);
    uint32_t data_length = ntohl(head[1]);
    char* data = new char[received_length + 1];
    memcpy(data, recv_buffer_ + sizeof(channel_id) +
            sizeof(data_length), received_length);
    Packet* packet = new Packet(channel_id);
    packet->set_packet(data, data_length);
    packet->set_end_point(end_point_);
    if (received_length == 0) {
        printf("disconnected\n");
        return -1;
    }
    net_handler_->OnReceived(packet);
    return 0;
}

int StreamSocketContext::AdjustBuffer(int received_length)
{
    if (received_length >= (recv_buffer_length_ / 2) &&
            recv_buffer_length_ < 1024 * 1024 * 10) {
        char* new_buffer = new char[2 * recv_buffer_length_];
        memcpy(new_buffer, recv_buffer_, received_length);
        delete [] recv_buffer_;
        recv_buffer_ = new_buffer;
        recv_buffer_length_ *= 2;
    } else if (received_length < recv_buffer_length_ / 3 &&
            recv_buffer_length_ > 111) {
        char* new_buffer = new char[recv_buffer_length_ / 2]; 
        memcpy(new_buffer, recv_buffer_, received_length);
        delete [] recv_buffer_;
        recv_buffer_ = new_buffer;
        recv_buffer_length_ /= 2;
    }
}
