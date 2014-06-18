// yuntang
// file:process.cpp
#include "process.h"
namespace cthread
{
void Processor::Process(int which_thread)
{
	TestFun(which_thread);
}
void Processor::TestFun(int which_thread)
{
	printf("this is thread %d\n", which_thread);
}
}


