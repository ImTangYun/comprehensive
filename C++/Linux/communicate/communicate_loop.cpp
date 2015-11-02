#include <unistd.h>
#include <stdio.h>
#include "communicate_loop.h"

using namespace cthread;

void CommunicateLoop::Run(CThread* cthread, void* args)
{
    int thread_id = *(int*)args;
    delete (int*)args;
    Process(thread_id);
}

void CommunicateLoop::Process(int thread_id)
{
    while (is_run_) {
        // printf("thread: %d\n", thread_id);
        usleep(10);
        HandleEvent();
    }
}

void CommunicateLoop::Init()
{
}

void CommunicateLoop::Start()
{
    if (is_run_) return;
    is_run_ = true;
    event_loop_thread_ = new CThread();
    int* which_thread = new int(0);
    event_loop_thread_->Start(this, (void*)which_thread);
}

void CommunicateLoop::Stop()
{
    is_run_ = false;
    event_loop_thread_->Join();
}

void CommunicateLoop::HandleEvent()
{
    struct epoll_event events[256];
    int nfds = epoll_wait(efd_, events, 256, 500);
    for (int i = 0; i < nfds; ++i) {
        if (events[i].events & EPOLLIN) {
            printf("EPOLLIN\n");
            SocketContext* socket_context = (SocketContext*)events[i].data.ptr;
            socket_context->HandleInput();
        } else if (events[i].events & EPOLLOUT) {
            printf("EPOLLOUT\n");
            SocketContext* socket_context = (SocketContext*)events[i].data.ptr;
            socket_context->HandleOutput();
        }
    }
}

int CommunicateLoop::AddEvent(SocketContext* socket_context,
        bool readable, bool writable)
{
    struct epoll_event ev;
    ev.data.ptr = (void*) socket_context;
    if (readable && !writable)
        ev.events = EPOLLET | EPOLLIN;
    if (readable && writable)
        ev.events = EPOLLOUT | EPOLLIN | 0;
    socket_context_list_.push_back(socket_context);
    return epoll_ctl(efd_, EPOLL_CTL_ADD, socket_context->fd(), &ev);
}

int CommunicateLoop::SetWritable(SocketContext* socket_context, bool writable)
{
    return 0;
}

int CommunicateLoop::ClearEvent(SocketContext* socket_context)
{
    return 0;
}
