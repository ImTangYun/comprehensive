#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "net_machine.h"
#include "packet.h"
#include "communicate_loop.h"
#include "net_handler.h"
#include "listen_handler.h"
#include "singleton.h"

int main()
{
    NetMachine* net_machine = Singleton<NetMachine>::Instance();
    NetHandler* net_handler = new ListenHandler();
    net_machine->AsyncListen(1235, net_handler);
    while (true) {
        sleep(1);
    }
    return 0;
}
