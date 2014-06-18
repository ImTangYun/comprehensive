#ifndef PROCESS_H_
#define PROCESS_H_
#include "Work_flow.h"
namespace cthread
{
class Processor : public WorkFlow
{
public:
	virtual void Process(int which_thread);
	void TestFun(int which_thread);
};
}


#endif // PROCESS_H_
