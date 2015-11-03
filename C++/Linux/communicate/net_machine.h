// 
// net machine
// 15/10/25
//

#ifndef NET_MACHINE
#define NET_MACHINE
#include <string>
#include "communicate_loop.h"
using std::string;
class Packet;
class NetHandler;

class NetMachine
{
    public:
        int Init();
        NetMachine():communicate_loop_(new CommunicateLoop()) {}
        int AsyncListen(int port, NetHandler* net_handler);
        int AsyncSendPacket(const string &ip_port, Packet* packet, NetHandler* net_handler);
    private:
        CommunicateLoop* communicate_loop_;
};

#endif
