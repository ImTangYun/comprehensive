#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "net_machine.h"
#include "packet.h"
#include "communicate_loop.h"
#include "net_handler.h"
#include "stream_handler.h"
#include "stream_socket_context.h"
#include "end_point.h"

int main()
{
    NetMachine net_machine;
    Packet* packet = new Packet();
    char* data = new char[100];
    uint32_t length = snprintf(data, 100, "hello world");
    packet->set_packet(data, length);
    NetHandler* net_handler = new StreamHandler();
    StreamSocketContext* socket_context = new
        StreamSocketContext("127.0.0.1:1235", net_handler, &net_machine);
    socket_context->Init();
    EndPoint* end_point = new EndPoint(socket_context);
    net_machine.AsyncSendPacket(end_point, packet, net_handler);
    // net_machine.AsyncSendPacket("127.0.0.1:1235", packet, net_handler);
    sleep(50);
    return 0;
}
