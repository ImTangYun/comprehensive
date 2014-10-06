#include <stdio.h>
//
// 方法一：暴力法，双重循环，超时
//
//
int solution(int A[], int length)
{
    if (length <= 0) return -1;
    int max = A[0];
    int tmp = 1;
    for (int i = 0; i < length; ++i) {
        for (int j = i; j < length; ++j) {
            tmp *= A[j];
            if (tmp > max) max = tmp;
        }
        tmp = 1;
    }
    return max;
}

//
// 方法二：时间复杂度（O(n)）
// 分析数组的特点：
// 1.数组中的0，如果有零，那么0要吗就是子数组之间的分割标志，要吗最大子数组的积就是0
// 2.数组中的负数，利用0分割成子数组之后，哥哥子数组的子数组的最大积的计算方法如下：
//      1.如果子数组元素个数为0，子数组的子数组的最大积为0
//      2.如果子数组元素个数为1，子数组的最大子数组积要吗为子数组中这个唯一元素，要吗为0
//      3.子数组中元素个数超过1的时候：
//              1.子数组中负数个数为偶数，直接子数组中所有元素的积就是该子数组中最大子数组积
//              2.子数组中负数个数为奇数：
//                      1.首先计算所有元素的积
//                      2.从头至尾扫描子数组，可以得到数组前半部分的积和后半部分的积，取所有出现过的积中最大的那个
//
//

int help(int A[], int front, int end)
{
    if (end - front <= 1) return 0;
    if (end - front == 2) return A[front + 1];
    int count = 0;
    int total = 1;
    for (int i =  front + 1; i < end; ++i) {
        total *= A[i];
        if (A[i] < 0) ++count;
    }
    if (count % 2 == 0) {
        return total;
    } else {
        int head = 1;
        int ret = A[front + 1];
        for (int i = front + 1; i < end; ++i) {
            head *= A[i];
            if (ret < head) ret = head;
            if (ret < total / head) ret = total / head;
        }
        return ret;
    }
}

int solution1(int A[], int length)
{
    if (length <= 0) {
        return -1;
    }
    if (length == 1) return A[0];
    int *zero_index = new int[length];
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (A[i] == 0) zero_index[count++] = i;
    }
    int max_p;
    if (count > 0) max_p = 0;
    else max_p = 1;
    for (int i = 0; i < count; ++i) {
        int ret;
        if (i == 0) {
            ret = help(A, -1, zero_index[i]);
        } else {
            ret = help(A, zero_index[i - 1], zero_index[i]);
        }
        if (max_p < ret) max_p = ret;
    }
    if (count > 0) {
        int ret = help(A, zero_index[count - 1], length);
        if (max_p < ret) max_p = ret;
    } else {
        int ret = help(A, -1, length);
        if (max_p < ret) max_p = ret;
    }
    return max_p;
}

int main()
{
    int A[] = {1, 2, 0, -3,-4};
    printf("%d\n", solution1(A, 5));
    return 0;
}

