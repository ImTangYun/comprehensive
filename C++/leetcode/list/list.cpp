#include "list.h"

namespace my_std
{
SingleListNode::SingleListNode()
{
	next = NULL;
}

SingleList::SingleList()
{
	head_ = NULL;
}
SingleList::~SingleList()
{
	SingleListNode* p = head_;
	SingleListNode* p1;
	while (p->next_ != NULL) {
		p1 = p->next_->next_;
		delete p;
		p = p1;
	}
}
template<typename T>
void PushFront(const T &value)
{
	SingleListNode* node = new SingleListNode;
	node.data_ = value;
	head_.next_ = node;
	size_++;
}
SingleListNode* SingleList::Front()
{
	return head_.next_;
}
uint32_t SingleList::size()
{
	return size_;
}
} // namespace my_std
