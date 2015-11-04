//
//
//
//
#ifndef SIMPLE_LIST
#define SIMPLE_LIST
template<typename T>
struct Node
{
    Node():next_(NULL), pre_(NULL){}
    Node(T data):next_(NULL), pre_(NULL), data_(T) {}
    Node* next_;
    Node* pre_;
    T data_;
};

class IteratorFun
{
    public:
        virtual void action(Node* node) = 0;
};
template<typename T>
class SimpleList
{
    public:
        SimpleList();
        ~SimpleList();
        Node* push_back(T t);
        void remove_node(Node* node_);
        void HandleEveryNode(IteratorFun* iter);
    private:
        Node head_;
        Node tail_;
        class IteratorDel: public IteratorFun
        {
            virtual void action(Node* node)
            {
                SimpleList::remove_node(node);
            }
        }
};

template<typename T>
SimpleList<T>::SimpleList()
{
}
template<typename T>
SimpleList<T>::~SimpleList()
{
    IteratorFun* fun = new IteratorDel();
    HandleEveryNode(fun);
}
template<typename T>
Node* SimpleList::push_back(T t)
{
    Node* node = new Node(t);
    if (head_.next_ == NULL || head_.next_ == &tail_) {
        head_ = node;
        tail_.pre_ = node;
        node->next_ = &tail_;
        node->pre_ = &head_;
        return node;
    }
    node->pre_ = tail_.pre_;
    node->next_ = &tail_;
    tail_.pre_ = node;
    return node;
}
template<typename T>
void SimpleList<T>::remove_node(Node* node)
{
    if (node == &head_ || node == &tail_) return;
    node->next_->pre_ = node->pre_;
    node->pre_->next_ = node->next_;
    delete node;
}
template<typename T>
void HandleEveryNode(IteratorFun* iter)
{
    
    if (head_.next_ == NULL || head_.next_ == &tail_) return;
    Node* node = head_.next_;
    while (node != &tail_) {
        Node* tmp = node->next_;
        iter->action(node);
        node = tmp;
    }
}
#endif
