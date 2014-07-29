#include <unistd.h>
#include <queue>
#include "taskqueue.h"

using std::queue;
namespace myspace
{
TaskQueue::TaskQueue():lock_(PTHREAD_MUTEX_INITIALIZER),limit_(10)
{
}
TaskQueue::TaskQueue(uint32_t limit):lock_(PTHREAD_MUTEX_INITIALIZER),limit_(limit)
{
}
TaskQueue::~TaskQueue()
{
    pthread_mutex_lock(&lock_);
    while (!Empty()) {
        char* p = (char*)Pop().data_;
        if (p != NULL) {
            delete p;
        }
    }
    pthread_mutex_destroy(&lock_);
}
void TaskQueue::Push(TaskNode node)
{
    bool success = false;
    while (!success) {
        pthread_mutex_lock(&lock_);
        if (data_queue_.size() < limit_) {
            data_queue_.push(node);
            success = true;
        }
        pthread_mutex_unlock(&lock_);
        if (!success) sleep(1);
    }
}
TaskNode TaskQueue::Pop()
{
    bool success = false;
    while (true) {
        pthread_mutex_lock(&lock_);
        TaskNode tmp; 
        if (!Empty()) {
            tmp = data_queue_.front();
            data_queue_.pop();
            success = true;
        }
        pthread_mutex_unlock(&lock_);
        if (!success) sleep(1);
        else return tmp;
    }
}
bool TaskQueue::Empty()
{
    return data_queue_.size() == 0;
}
} // namespace myspace

