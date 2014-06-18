#include <stdio.h>
#include "process.h"
using cthread::Processor;
int main()
{
	Processor x;
	x.Init(5);
	x.Start();
    return 0;
}

