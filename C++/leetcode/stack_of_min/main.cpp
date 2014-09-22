// yuntang
// file: main.cpp
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_of_min.h"

using my_algorithm::StackOfMin;

int main()
{
	srand(time(0));
	StackOfMin my_stack;
	my_stack.Push(5);
	printf("Top(): %d\n", my_stack.Top());
	printf("min(): %d\n", my_stack.min());
	for (int i = 0; i < 100; ++i) {
		my_stack.Push(rand() % 100);	
	}
	for (int i = 0; i < 101; ++i) {
		printf("Top(): %d min(): %d\n",
				my_stack.Top(), my_stack.min());
		my_stack.Pop();
	}
	return 0;
}
