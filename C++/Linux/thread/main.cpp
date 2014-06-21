#include <stdio.h>
#include <unistd.h>
#include "Work_flow.h"
#include "process.h"
using cthread::WorkFlow;
using cthread::Processor;
int main()
{
	WorkFlow work;
	work.Init(10);
	work.Start();
	sleep(10);
	Processor x;
	x.Init(2);
	//x.Init(5);
	x.Start();
	sleep(100);
    return 0;
}

