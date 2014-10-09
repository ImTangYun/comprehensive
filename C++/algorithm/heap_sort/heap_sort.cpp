#include <stdio.h>

// for test
void Print_heap(int A[], int heap_size)
{
    int x = 0;
    int s = heap_size;
    for (int i = 1; i < heap_size; i *= 2) {
        x += i;
        int m = heap_size - i / 2;
        for (int c = 0; c < m; ++c) {
            printf(" ");
        }
        for (int j = x - i; j < x && j < heap_size; ++j) {
            printf("%d ", A[j]);
        }
        printf("\n");
    }
}

inline int left(int i)
{
    return 2 * i + 1;
}

inline int right(int i)
{
    return 2 * i + 2;
}

inline void swap_(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void heapify(int A[], int node, int heap_size)
{
    if (node >= heap_size) return;
    int l = left(node);
    int r = right(node);
    int h = node;
    int max = A[node];
    if (l < heap_size && A[l] > max) {
        h = l;
        max = A[l];
    }
    if ( r < heap_size && A[r] > max) {
        h = r;
    }
    if (h != node) {
        swap_(A[node], A[h]);
        heapify(A, h, heap_size);
    }
}

void build_max_heap(int A[], int heap_size)
{
    for (int i = heap_size / 2; i >= 0; --i) {
        heapify(A, i, heap_size);
        Print_heap(A, heap_size);
    }
}

void heap_sort(int A[], int heap_size)
{
    build_max_heap(A, heap_size);
    for (int i = heap_size - 1; i >= 0; --i) {
        swap_(A[0], A[i]);
        heapify(A, 0, i);
        // Print_heap(A, heap_size);
    }
}

int main()
{
    int A[] = {1,9,3,4,5,6,7,8,9};
    Print_heap(A, 9);
    // build_max_heap(A, 9);
    heap_sort(A, 9);
    Print_heap(A, 9);
    return 0;
}
