
/*
对某个值A[i]来说，能trapped的最多的water取决于在i之前最高的值leftMostHeight[i]和在i右边的最高的值rightMostHeight[i]（均不包含自身）。

如果min(left,right) > A[i]，那么在i这个位置上能trapped的water就是min(left,right) – A[i]。

有了这个想法就好办了，第一遍从左到右计算数组leftMostHeight，第二遍从右到左计算rightMostHeight。

时间复杂度是O(n)。
*/
class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        int front = 0;
        int end = n - 1;
        int tmp = 0;
        int water = 0;
        for (int i = 0; i <= end; ++i) {
            int dif = A[front] - A[i];
            if (dif > 0) {
                tmp += dif;
            } else {
                water += tmp;
                tmp = 0;
                front = i;
            }
        }
        tmp = 0;
        for (int i = end; i >= front; --i) {
            int dif = A[end] - A[i];
            if (dif > 0) {
                tmp += dif;
            } else {
                water += tmp;
                tmp = 0;
                end = i;
            }
        }
        return water;
    }
};
