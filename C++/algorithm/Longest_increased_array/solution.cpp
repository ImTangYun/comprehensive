//
// 动态规划法（时间复杂度O(N^2))
// 设长度为N的数组为{a0，a1, a2, ...an-1)，则假定以aj结尾的数组序列的最长递增子序列长度为L(j)，
// 则L(j)={ max(L(i))+1, i<j且a[i]<a[j] }。也就是说，我们需要遍历在j之前的所有位置i(从0到j-1)，
// 找出满足条件a[i]<a[j]的L(i)，求出max(L(i))+1即为L(j)的值。最后，我们遍历所有的L(j)（从0到N-1），
// 找出最大值即为最大递增子序列。时间复杂度为O(N^2)。
// 例如给定的数组为{5，6，7，1，2，8}，则L(0)=1, L(1)=2, L(2)=3, L(3)=1, L(4)=2, L(5)=4。
// 所以该数组最长递增子序列长度为4，序列为{5，6，7，8}。算法代码如下：
//
#include <stdio.h>
#include <stack>
using std::stack;
int longest(int* A, int length)
{
    int *b = new int[length];
    int *c = new int[length];
    for (int i = 0; i < length; ++i) {
        c[i] = i;
    }
    b[0] = 1;
    int max = 1;
    int max_end = 0;
    for (int i = 0; i < length; ++i) {
        b[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (A[i] >= A[j]) {
                int tmp = b[j] + 1;
                if (b[i] < tmp) {
                    b[i] = tmp;
                    c[i] = j;
                }
            }
        }
        if (max < b[i]) {
            max = b[i];
            max_end = i;
        }
    }
    stack<int> ret;
    int i = max_end;
    while (c[i]!= i) {
        ret.push(A[i]);
        i = c[i];
    }
    ret.push(A[i]);
    while (!ret.empty()) {
        printf("%d ", ret.top());
        ret.pop();
    }
    printf("\n");
    delete [] b;
    delete [] c;
    return max;
}

int main()
{
    int m[] = {1,2,3,4,1,2,1,2,5,7,6,8,3,19};
    printf("ret: %d\n", longest(m, 14));
    return 0;
}

