#ifndef QUEUE_H_
#define QUEUE_H_

#include <stack>
using std::stack;

namespace myspace
{
template<typename T>
class queue
{
public:
    queue():flag(true){}
    ~queue(){}
    void push(const T &value);
    void pop();
    bool empty();
    T top();
private:
    void adjust(stack<T> &s1, stack<T> &s2);
    stack<T> s1;
    stack<T> s2;
    bool flag;
};

template<typename T>
void queue<T>::adjust(stack<T> &s1, stack<T> &s2)
{
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    flag = !flag;
}
template<typename T>
void queue<T>::push(const T &value)
{
    if (!flag)
        adjust(s2, s1);
    s1.push(value);
}
template<typename T>
void queue<T>::pop()
{
    if (flag)
        adjust(s1, s2);
    s2.pop();
}
template<typename T>
T queue<T>::top()
{
    if (flag)
        adjust(s1, s2);
    return s2.top();
}
template<typename T>
bool queue<T>::empty()
{
    return s1.empty() && s2.empty();
}
} // namspace myspace

#endif // QUEUE_H_
