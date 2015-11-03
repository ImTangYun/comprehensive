//
//
//
//
#ifndef SOCKET_CONTEXT
#define SOCKET_CONTEXT
#include <string>
// #include "communicate_loop.h"
class CommunicateLoop;
using std::string;
class SocketContext
{
    public:
        SocketContext(CommunicateLoop* communicate_loop):communicate_loop_(communicate_loop){}
        SocketContext(const string ip_port, CommunicateLoop* communicate_loop):ip_port_(ip_port),
            ip_(NULL), port_(-1), fd_(-1), communicate_loop_(communicate_loop){}
        virtual ~SocketContext()
        {
            delete ip_;
            ip_ = NULL;
        }
        int fd() {return fd_;}
        void set_fd(int fd) {fd_ = fd;}
        virtual int HandleOutput() = 0;
        virtual int HandleInput() = 0;
        virtual void OnReceived() = 0;
        int ParseIpPort();
        void set_communicate_loop(CommunicateLoop* communicate_loop)
        {
            communicate_loop_ = communicate_loop;
        }
    protected:
        CommunicateLoop* communicate_loop_;
        string ip_port_;
        char* ip_;
        int port_;
        int fd_;
};
#endif
