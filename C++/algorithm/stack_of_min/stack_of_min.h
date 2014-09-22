// yuntang
// file: stack_of_min.h
#ifndef ALGORITHM_STACK_OF_MIN_STACK_OF_MIN_H_
#define ALGORITHM_STACK_OF_MIN_STACK_OF_MIN_H_ 1
#include <stack>
namespace my_algorithm
{
using std::stack;
class StackOfMin
{
	public:
		StackOfMin();
		~StackOfMin();
		void Push(int value);
		int Top();
		void Pop();
		int min();
	private:
		stack<int> data_;
		stack<int> min_data_;
		
};
} // my_algorithm
#endif // ALGORITHM_STACK_OF_MIN_STACK_OF_MIN_H_
