// yuntang
// file:list.h
#ifndef ALGORITHM_LIST_LIST_H_
#define ALGORITHM_LIST_LIST_H_ 1
namespace my_std
{
template<typename T>
struct SingleListNode
{
	SingleListNode();
	SingleListNode* next_;
	T data_;
};

class SingleList
{
	public:
		SingleList();
		~SingleList();
		template<typename T>
		void PushFront(const T &value);
		SingleListNode* Front();
		uint32_t size();
	private:
		uint32_t size_;
		SingleListNode head_;
};
} // namespace my_std
#endif // ALGORITHM_LIST_LIST_H_
