//
// 思想：维护一个数组B，遍历A数组的时候查找B数组中的大于A[i]的第一个数，然后替换成A[i]
// 查找过程用二分法，提高效率
// 如果B最大的数都比A[i]小那么就在B后面新添加一个数，值为A[i]
//
//
//


#include <stdio.h>
#include <stack>
using std::stack;
int bin_search(int* A, int length, int target)
{
    if (length <= 0) return -1;
    if (A[length - 1] < target) {
        return -2;
    }
    int front = 0;
    int end = length - 1;
    while (front < end) {
        int middle = (front + end) / 2;
        if (A[middle] == target) return middle;
        else if (A[middle] < target) {
            front = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return end;
}

int longest(int* A, int length)
{
    int *B = new int[length];
    int max_index = 1;
    B[0] = A[0];
    for (int i = 1; i < length; ++i) {
        int ret = bin_search(B, max_index, A[i]);
        if (ret == -2) {
            B[max_index] = A[i];
            ++max_index;
        } else {
            B[ret] = A[i];
        }
    }
    for (int i = 0; i < max_index; ++i) {
        printf("%d ", B[i]);
    }
    printf("\n");
    delete [] B;
    return max_index;
}

int main()
{
    printf("solution2\n");
    int m[] = {1,2,3,4,1,2,1,2,5,7,6,8,3,19};
    printf("ret: %d\n", longest(m, 14));
    return 0;
}

