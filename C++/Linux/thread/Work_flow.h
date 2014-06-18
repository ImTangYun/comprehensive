#ifndef WORK_FLOW_H_
#define WORK_FLOW_H_
#include <map>
#include "Cthread.h"
namespace cthread
{
class WorkFlow : public Runnuble
{
public:
	WorkFlow();
	virtual ~WorkFlow(){}
	bool Init(int thread_num);
	virtual void Process(int which_thread);
	virtual void Run(CThread* thread, void* args);
	void Start();
	void Stop();
private:
	std::map<int, CThread*> thread_;
	int thread_num_;
};
}

#endif // WORK_FLOW_H_
