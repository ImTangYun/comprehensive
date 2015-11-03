//
//
//
//
#ifndef NET_HANDLER
#define NET_HANDLER
class Packet;
class NetHandler
{
    public:
        virtual int OnReceived(Packet* packet) = 0;
        virtual int OnAccepted(int fd) = 0;
        virtual int OnSent(Packet* packet) = 0;
        virtual int OnTimeOut() = 0;
};
#endif
