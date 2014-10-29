#ifndef VECTOR_H_
#define VECTOR_H_

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
    T operator[](uint32_t i);
    uint32_t size() {return size_;}
    void resize(const T &s);
    uint32_t capacity() {return capacity_;}
    void clear() { size_ = 0; end_ = data_;}
    iterator begin() {return begin_;}
    iterator end() {return end_; }
private:
    uint32_t capacity_;
    T* data_;
    iterator begin_;
    iterator end_;
    uint32_t size_;
};

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
        T* p = data_;
        capacity_ *= 2;
        data_ = new T[capacity_];
        begin_ = data_;
        end_ = data_ + size_;
        for (int i = 0; i < size_; ++i) {
            data_[i] = p[i];
        }
        delete [] p;
    }
    data_[size_] = v;
    ++end_;
    ++size_;
}
template<typename T>
void vector<T>::resize(const T &s)
{
    if (capacity_ <= 2 * s) {
        T* p = data_;
        capacity_ *= 2;
        data_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = p[i];
        }
        delete [] p;
    }
    size_ = s;
    end_ = data_ + size_;
}
#endif // VECTOR_H_
