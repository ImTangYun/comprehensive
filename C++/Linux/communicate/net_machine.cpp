// 
// net machine
// 15/10/25
//
#include <stdio.h>
#include "packet.h"
#include "net_machine.h"
#include "stream_socket_context.h"
#include "listen_socket_context.h"
int NetMachine::Init()
{
    communicate_loop_->Start();
    return 0;
}
int NetMachine::AsyncListen(int port, NetHandler* net_handler)
{
    ListenSocketContext* listen_socket_context = new ListenSocketContext(
            port, communicate_loop_, net_handler);
    listen_socket_context->Init();
    communicate_loop_->Start();
    return 0;
}
int NetMachine::AsyncSendPacket(const string &ip_port,
        Packet* packet, NetHandler* net_handler)
{
    StreamSocketContext* stream_socket_context = new
        StreamSocketContext(ip_port, communicate_loop_, net_handler);

    printf("ptr of communicate_loop_ in NetMachine is: %p\n", communicate_loop_);
    stream_socket_context->Init();
    printf("stream_socket_context init success!\n");
    communicate_loop_->Start();
    for (int i = 0; i < 3; ++i) {
        stream_socket_context->AsyncSendPacket(packet);
        sleep(1);
    }
    return 0;
}
