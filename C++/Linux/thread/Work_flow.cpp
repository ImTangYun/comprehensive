// yuntang
// file:work_flow.cpp
#include <unistd.h>
#include "Work_flow.h"
namespace cthread
{
bool WorkFlow::Init(int thread_num)
{
	thread_num_ = thread_num;
	return true;
}
void WorkFlow::Start()
{
	CThread* thread;
	for (int i = 0; i < thread_num_; ++i) {
		thread = new CThread;
		int* which_thread = new int(i);
		thread->Start(this, (void*)which_thread);
		thread_[i] = thread;
	}
}
void WorkFlow::Run(CThread* thread, void* args)
{
	while (1) {
		int *which_thread = (int*)args;
		Process(*which_thread);
		sleep(1);
	}
}
} // namespace cthread
