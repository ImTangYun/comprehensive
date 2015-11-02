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

class NetMachine
{
    public:
        int Init();
        NetMachine():communicate_loop_(new CommunicateLoop()) {}
        int AsyncListen(int port);
        int AsyncSendPacket(const string &ip_port, Packet* packet);
    private:
        CommunicateLoop* communicate_loop_;
};

#endif
