//
//
//
//
#ifndef STREAM_HANDLER
#define STREAM_HANDLER
#include "packet.h"
#include "net_handler.h"
class StreamHandler: public NetHandler
{
    public:
        virtual int OnReceived(Packet* packet)
        {
            char* data = packet->data();
            uint32_t length = packet->data_length();
            data[length] = '\n';
            printf("received: %s\n", data);
            return 0;
        }
        virtual int OnAccepted(int fd){ return 0;}
        virtual int OnSent(Packet* packet)
        {
            char* data = packet->data();
            uint32_t length = packet->data_length();
            data[length] = '\n';
            printf("received: %s\n", data);
            return 0;
        }
        virtual int OnTimeOut(){return 0;}
};
#endif
