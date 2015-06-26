#ifndef _TASK_QUEUE_H_
#define _TASK_QUEUE_H_
#include <pthread.h>
#include <stdint.h>
#include <queue>
#include <unistd.h>

using std::queue;
namespace myspace
{
struct TaskNode
{
    void* data_;
    int length_; // byte length of data_;
    ~TaskNode()
    {
        delete [] (char*)data_;
    }
};
template<typename T>
class TaskQueue
{
public:
    TaskQueue();
    TaskQueue(uint32_t limit);
    ~TaskQueue();
    void Push(T node);
    void PlianPush(T node);
    T Pop();
    T Poll(int time);
    uint32_t size();
    bool Empty();
private:
    queue<T> data_queue_;
    pthread_mutex_t lock_;
    uint32_t limit_;
};

template<typename T>
TaskQueue<T>::TaskQueue():lock_(PTHREAD_MUTEX_INITIALIZER),
    limit_(10)
{
}
template<typename T>
TaskQueue<T>::TaskQueue(uint32_t limit):lock_(
        PTHREAD_MUTEX_INITIALIZER),limit_(limit)
{
}
template<typename T>
TaskQueue<T>::~TaskQueue()
{
    pthread_mutex_lock(&lock_);
    /*while (!Empty()) {
        char* p = (char*)Pop().data_;
        if (p != NULL) {
            delete p;
        }
    }*/
    pthread_mutex_destroy(&lock_);
}

// put data until success
template<typename T>
void TaskQueue<T>::Push(T node)
{
    bool success = false;
    while (!success) {
        pthread_mutex_lock(&lock_);
        if (data_queue_.size() < limit_) {
            data_queue_.push(node);
            success = true;
        }
        pthread_mutex_unlock(&lock_);
        if (!success) usleep(1000);
    }
}
// push without any lock, make sure to do
// this by single thread at a time
template<typename T>
void TaskQueue<T>::PlianPush(T node)
{
    data_queue_.push(node);
}

// get data until success
template<typename T>
T TaskQueue<T>::Pop()
{
    while (true) {
        pthread_mutex_lock(&lock_);
        T tmp; 
        if (!Empty()) {
            tmp = data_queue_.front();
            data_queue_.pop();
            pthread_mutex_unlock(&lock_);
            return tmp;
        }
        pthread_mutex_unlock(&lock_);
        usleep(1000);
    }
}

// pop data with a limited time, that if can't
// get a data in this time a NULL will be returned
// the time unit is 0.1 milisecond
template<typename T>
T TaskQueue<T>::Poll(int time)
{
    while (time > 0) {
        pthread_mutex_lock(&lock_);
        T tmp; 
        if (!Empty()) {
            tmp = data_queue_.front();
            data_queue_.pop();
            pthread_mutex_unlock(&lock_);
            return tmp;
        }
        pthread_mutex_unlock(&lock_);
        usleep(100);
        --time;
    }
    return (T)0;
}
template<typename T>
uint32_t TaskQueue<T>::size()
{
    return data_queue_.size();
}
template<typename T>
bool TaskQueue<T>::Empty()
{
    return data_queue_.size() == 0;
}
} // namespace myspace

#endif // _TASK_QUEUE_H_
