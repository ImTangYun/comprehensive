#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "net_machine.h"
#include "packet.h"
#include "communicate_loop.h"

int main()
{
    NetMachine net_machine;
    Packet* packet = new Packet();
    char* data = new char[100];
    uint32_t length = snprintf(data, 100, "hello world");
    packet->set_packet(data, length);
    // net_machine.AsyncSendPacket("127.0.0.1:6666", packet);
    // net_machine.AsyncSendPacket("127.0.0.1:6666", packet);
    // net_machine.AsyncSendPacket("127.0.0.1:6666", packet);
    net_machine.AsyncListen(1235);
    while (true) {
        sleep(1);
    }
    return 0;
}
