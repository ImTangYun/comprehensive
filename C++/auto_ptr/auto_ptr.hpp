#ifndef AUTO_PTR
#define AUTO_PTR
#include <stdio.h>
namespace myspace
{

template <typename T>
class AutoPtr
{
public:
    AutoPtr(T* p );
    ~AutoPtr();
    AutoPtr(const AutoPtr& A);
    AutoPtr &operator=(const AutoPtr &A);
    T* operator->();
    T &operator*();
    const T &operator*() const;
private:
    void Decref();
    T* data_ptr_;
    size_t *count_;
};

template<typename T>
AutoPtr<T>::AutoPtr(T* p):data_ptr_(p)
{
    count_ = new size_t(1);
}

template<typename T>
AutoPtr<T>::~AutoPtr()
{
    Decref();
}
template<typename T>
AutoPtr<T>::AutoPtr(const AutoPtr& A)
{
    ++*A->count_;
    Decref();
    data_ptr_ = A.data_ptr_;
    count_ = A.count_;
}

template<typename T>
AutoPtr<T> &AutoPtr<T>::operator=(const AutoPtr &A)
{
    ++*A->count_;
    Decref();
    data_ptr_ = A.data_ptr_;
    count_ = A.count_;
    return *this;
}

template<typename T>
T* AutoPtr<T>::operator->()
{
    return data_ptr_;
}

template<typename T>
T &AutoPtr<T>::operator*()
{
    return *data_ptr_;
}

template<typename T>
const T &AutoPtr<T>::operator*() const
{
    return *data_ptr_;
}

template<typename T>
void AutoPtr<T>::Decref()
{
    if (--*count_ == 0) {
        delete data_ptr_;
        delete count_;
    }
}
}
#endif
