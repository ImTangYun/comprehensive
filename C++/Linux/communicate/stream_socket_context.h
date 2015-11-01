//
//
//

#ifndef STREAM_SOCKET_CONTEXT
#define STREAM_SOCKET_CONTEXT
#include <string>
#include "task_queue.h"
using std::string;
using myspace::TaskQueue;
class Packet;
class CommunicateLoop;
class StreamSocketContext
{
    public:
        StreamSocketContext(const string &ip_port,
                CommunicateLoop* communicate_loop):ip_port_(ip_port),
                communicate_loop_(communicate_loop),ip_(NULL), port_(-1),
                fd_(-1), packet_queue_(new TaskQueue<Packet*>()) {}
        int Init();
        int AsyncSendPacket(Packet* packet);
        int fd() {return fd_;}
        int HandleOutput();
        int HandleInput();
    private:
        int Send(char* data, int32_t length);
        CommunicateLoop* communicate_loop_;
        int ParseIpPort();
        string ip_port_;
        char* ip_;
        int port_;
        int fd_;
        TaskQueue<Packet*>* packet_queue_;
};

#endif
