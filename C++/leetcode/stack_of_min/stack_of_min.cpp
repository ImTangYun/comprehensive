// yuntang
// file: stack_of_min.cpp
#include <stack>
#include "stack_of_min.h"
namespace my_algorithm
{
using std::stack;
StackOfMin::StackOfMin()
{
}
StackOfMin::~StackOfMin()
{
}
void StackOfMin::Push(int value)
{
	data_.push(value);
	if (min_data_.size() == 0 || value <= min_data_.top()) {
		min_data_.push(value);
	}
}
int StackOfMin::Top()
{
	return data_.top();
}
void StackOfMin::Pop()
{
	if (data_.size() > 0) {
		if (min_data_.top() == data_.top() ) {
			min_data_.pop();
		}
		data_.pop();
	}
}
int StackOfMin::min()
{
	return min_data_.top();
}
} // my_algorithm
