#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <assert.h>
#include <stdint.h>
template<typename T>
class vector
{
public:
    vector();
    ~vector();
    typedef T* iterator;
    void push_back(const T &v);
    void pop_back();
    T operator[](uint32_t i);
    uint32_t size() {return size_;}
    void resize(const T &s);
    uint32_t capacity() {return capacity_;}
    void clear() { size_ = 0; end_ = data_;}
    iterator begin() {return begin_;}
    iterator end() {return end_; }
    void reserve(const T cap);
protected:
    void realloc();
private:
    uint32_t capacity_;
    T* data_;
    iterator begin_;
    iterator end_;
    uint32_t size_;
};

template<typename T>
void vector<T>::realloc()
{
    T* p = data_;
    data_ = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
        data_[i] = p[i];
    }
    begin_ = data_;
    end_ = data_ + size_;
    delete [] p;
}
template<typename T>
vector<T>::vector():capacity_(10), data_(new T[capacity_]),
    begin_(data_), end_(data_), size_(0)
{
}
template<typename T>
vector<T>::~vector()
{
    delete [] data_;
}
template<typename T>
T vector<T>::operator[](uint32_t i)
{
    assert(i < capacity_);
    return *(data_ + i);
}
template<typename T>
void vector<T>::push_back(const T &v)
{
    if (size_ == capacity_) {
        capacity_ *= 2;
        realloc();
    }
    data_[size_] = v;
    ++end_;
    ++size_;
}
template<typename T>
void vector<T>::resize(const T &s)
{
    if (capacity_ <= 2 * s) {
        capacity_ = 2 * s;
        realloc();
    }
    size_ = s;
    end_ = data_ + size_;
}
template<typename T>
void vector<T>::reserve(const T cap)
{
    if (cap > capacity_) {
        capacity_ = cap;
        realloc();
    }
}
template<typename T>
void vector<T>::pop_back()
{
    if (size_ > 0) {
        --size_;
        --end_;
        if (size_ * 3 < capacity_ && capacity_ > 10) {
            capacity_ /= 2;
            realloc();
        }
    }
}
#endif // VECTOR_HPP_
