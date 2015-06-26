#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include "taskqueue.h"
using myspace::TaskNode;
using myspace::TaskQueue;
typedef TaskQueue<TaskNode*>* TaskQueuePtr;
int i = 0;
pthread_mutex_t lock;
struct node
{
    int a;
    int b;
    int c;
    node(int a1, int b1)
    {
        a = a1;
        b = b1;
        c = 0;
    }
};
void* pfun_add(void* arg)
{
    printf("called me \n");
    TaskQueuePtr* taskQueuePtr = (TaskQueuePtr*)arg;
    while (taskQueuePtr[0]->size() > 0) {
        TaskNode* input = taskQueuePtr[0]->Poll(10);
        if (input != 0) {
            node* task = (node*)input->data_;
            for (int i = 0; i < 1000000; ++i)
                task->c = task->a + task->b;
            taskQueuePtr[1]->Push(input);
        }
    }
    return (void*)NULL;
}
int main()
{
    timeval starttime, endtime, lasttime;
    gettimeofday(&starttime,0);
    TaskQueuePtr taskQueue[2];
    taskQueue[0] = new TaskQueue<TaskNode*>(10000000);
    taskQueue[1] = new TaskQueue<TaskNode*>(10000000);
    for (int i = 0; i < 900; ++i) {
        TaskNode* taskNode = new TaskNode();
        node* n = new node(i, i + 1);
        taskNode->data_ = (void*)n;
        taskQueue[0]->PlianPush(taskNode);
    }
    pthread_t pid;
    for (int i = 0; i < 8; ++i) {
        pthread_create(&pid, NULL, pfun_add, (void*)taskQueue);
        assert(pid > 0);
    }
    int count = 900;
    while (count-- > 0) {
        // TaskNode* task = taskQueue[1]->Pop();
        delete[] (char*)taskQueue[1]->Pop();
        // node* n = (node*)(task->data_);
        // printf("%d + %d = %d\n", n->a, n->b, n->c);
    }
    gettimeofday(&endtime,0);
    double timeuse = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
    printf("time used: %f\n", timeuse);
    int a;
    for (int i = 0; i < 900; ++i) {
        for (int j = 0; j < 1000000; ++j) {
            int b = 100;
            int c = 100;
            a = b + c;
        }
    }
    gettimeofday(&lasttime,0);
    double timeuse1 = 1000000*(lasttime.tv_sec - starttime.tv_sec) + lasttime.tv_usec - starttime.tv_usec;
    printf("%dtime used: %f\n", a, timeuse1 - timeuse);

    return 0;
}
