#include <stdio.h>
#include <queue>

using std::queue;
template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void partition(T* arr, int front, int end, queue<int> &help_q)
{
    if (front >= end) return;
    int p1 = front;
    int p2 = front;
    while (p2 <= end) {
        if (arr[front] > arr[p2]) {
            ::swap<T>(arr[++p1], arr[p2]);
        }
        ++p2;
    }
    ::swap<T>(arr[front], arr[p1]);
    help_q.push(front);
    help_q.push(p1);
    help_q.push(front + 1);
    help_q.push(end);
}

template<typename T>
void quick_sort(T* arr, int length)
{
    if (length <= 1) return;
    queue<int> help_q;
    help_q.push(0);
    help_q.push(length - 1);
    while (!help_q.empty()) {
        int front = help_q.front();
        help_q.pop();
        int end = help_q.front();
        help_q.pop();
        partition<T>(arr, front, end, help_q);
    }
}
void print(int a[], int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
int main()
{
    int a[] = {7,6,7,2,3,4,6,5};
    quick_sort<int>(a, 8);
    print(a, 8);
    return 0;
}

