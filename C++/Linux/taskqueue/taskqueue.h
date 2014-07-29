#ifndef _TASK_QUEUE_H_
#define _TASK_QUEUE_H_
#include <pthread.h>
#include <stdint.h>
#include <queue>

using std::queue;
namespace myspace
{
struct TaskNode
{
    void* data_;
    int length_; // byte length of data_;
};

class TaskQueue
{
public:
    TaskQueue();
    TaskQueue(uint32_t limit);
    ~TaskQueue();
    void Push(TaskNode node);
    TaskNode Pop();
    bool Empty();
private:
    queue<TaskNode> data_queue_;
    pthread_mutex_t lock_;
    uint32_t limit_;
};
} // namespace myspace

#endif // _TASK_QUEUE_H_
