#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "taskqueue.h"
using myspace::TaskNode;
using myspace::TaskQueue;
TaskQueue q;
int i = 0;
void* pfunc_generate_task(void* arg)
{
    while (true) {
        ++i;
        char* p = new char[100];
        snprintf(p, 100, "this is data %d\n", i);
        TaskNode tmp;
        tmp.data_ = (void*)p;
        tmp.length_ = 100;
        q.Push(tmp);
        printf("pushed: %d\n", i);
        sleep(1);
    } 
    return (void*)NULL;
}
void* pfunc_process_task(void* arg)
{
    while (true) {
        printf("poped: %s", (char*)q.Pop().data_);
        sleep(2);
    } 
    return (void*)NULL;
}
int main()
{
    for (int i = 0; i < 1; ++i) {
        char* p = new char[100];
        snprintf(p, 100, "this is data %d\n", i);
        TaskNode tmp;
        tmp.data_ = (void*)p;
        tmp.length_ = 100;
        q.Push(tmp);
    }
    pthread_t pid1;
    pthread_create(&pid1, NULL, pfunc_generate_task, NULL);
    pthread_t pid2;
    pthread_create(&pid2, NULL, pfunc_process_task, NULL);
    while (!q.Empty()) {
        printf("%s", (char*)q.Pop().data_);
    }
    while (true);
    return 0;
}
