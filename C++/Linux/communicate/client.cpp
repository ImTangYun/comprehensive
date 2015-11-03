#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "net_machine.h"
#include "packet.h"
#include "communicate_loop.h"
#include "net_handler.h"
#include "stream_handler.h"

int main()
{
    NetMachine net_machine;
    Packet* packet = new Packet();
    char* data = new char[100];
    uint32_t length = snprintf(data, 100, "hello world");
    packet->set_packet(data, length);
    NetHandler* net_handler = new StreamHandler();
    net_machine.AsyncSendPacket("127.0.0.1:1235", packet, net_handler);
    sleep(50);
    return 0;
}
