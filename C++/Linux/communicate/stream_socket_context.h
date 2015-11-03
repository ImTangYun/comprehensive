//
//
//

#ifndef STREAM_SOCKET_CONTEXT
#define STREAM_SOCKET_CONTEXT
#include <string>
#include "task_queue.h"
#include "socket_context.h"
using std::string;
using myspace::TaskQueue;
class Packet;
class CommunicateLoop;
class NetHandler;
class StreamSocketContext: public SocketContext
{
    public:
        StreamSocketContext(const string &ip_port,
                CommunicateLoop* communicate_loop, NetHandler* net_handler):
                SocketContext(ip_port, communicate_loop),
                packet_queue_(new TaskQueue<Packet*>()), recv_buffer_(new char[111]),
                recv_buffer_length_(111),
                net_handler_(net_handler){}
        ~StreamSocketContext()
        {
            delete packet_queue_;
            packet_queue_ = NULL;
            delete [] recv_buffer_;
            recv_buffer_ = NULL;
        }
        int Init();
        int AsyncSendPacket(Packet* packet);
        virtual int HandleOutput();
        virtual int HandleInput();
        virtual void OnReceived() {}
        int AdjustBuffer(int received_length);
    private:
        int Send(char* data, uint32_t length);
        TaskQueue<Packet*>* packet_queue_;
        char* recv_buffer_;
        int recv_buffer_length_;
        NetHandler* net_handler_;
};

#endif
