// 
// net machine
// 15/10/25
//
#include <stdio.h>
#include "packet.h"
#include "net_machine.h"
#include "stream_socket_context.h"

int NetMachine::Listen(int port)
{

}
int NetMachine::AsyncSendPacket(const string &ip_port, Packet* packet)
{
    StreamSocketContext* stream_socket_context = new
        StreamSocketContext(ip_port, communicate_loop_);

    printf("ptr of communicate_loop_ in NetMachine is: %p\n", communicate_loop_);
    stream_socket_context->Init();
    printf("stream_socket_context init success!\n");
    stream_socket_context->AsyncSendPacket(packet);
    communicate_loop_->Start();
    return 0;
}
