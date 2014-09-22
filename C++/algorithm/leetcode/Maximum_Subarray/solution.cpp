
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int num1 = A[0];
        int num2 = A[0];
        for (int i = 1; i < n; ++i) {
            if (num1 < 0) num1 = A[i];
            else num1 += A[i];
            if (num2 < num1) num2 = num1;
        }
        return num2;
    }
};
