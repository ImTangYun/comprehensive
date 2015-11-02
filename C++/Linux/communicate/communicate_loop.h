//
//
//
#ifndef COMMUNICATE_LOOP
#define COMMUNICATE_LOOP
#include <sys/epoll.h>
#include <list>
#include "cthread.h"
#include "socket_context.h"
using std::list;
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
        int AddEvent(SocketContext* socket_context,
                bool readable, bool writable);
        int SetWritable(SocketContext* socket_context, bool writable);
        int ClearEvent(SocketContext* socket_context);
        void HandleEvent();
        virtual ~CommunicateLoop()
        {
            Stop();
            delete event_loop_thread_;
            event_loop_thread_ = NULL;

            for (list<SocketContext*>::iterator iter = socket_context_list_.begin();
                    iter != socket_context_list_.end(); ++iter) {
                delete *iter;
                *iter = NULL;
            }
        }
        int efd() {return efd_;}
    private:
        list<SocketContext*> socket_context_list_;
        bool is_run_;
        CThread *event_loop_thread_;
        int efd_;

};

#endif
