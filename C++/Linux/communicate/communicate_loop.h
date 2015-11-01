//
//
//
#ifndef COMMUNICATE_LOOP
#define COMMUNICATE_LOOP
#include <sys/epoll.h>
#include "cthread.h"
#include "stream_socket_context.h"
using namespace cthread;
class CommunicateLoop: public Runnuble
{

    public:
        virtual void Run(CThread* cthread, void* args);
        CommunicateLoop():efd_(epoll_create(256)) {}
        void Process(int thread_id);
        void Init();
        void Start();
        void Stop();
        int AddEvent(StreamSocketContext* socket_context,
                bool readable, bool writable);
        int SetWritable(StreamSocketContext* socket_context, bool writable);
        int ClearEvent(StreamSocketContext* socket_context);
        void HandleEvent();
        virtual ~CommunicateLoop()
        {
            Stop();
            delete event_loop_thread_;
        }
        int efd() {return efd_;}
    private:
        bool is_run_;
        CThread *event_loop_thread_;
        int efd_;
};

#endif
