
class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; ++i) {
            int tmp1 = (~one) & (~two) & A[i];
            int tmp2 = (one & (~two) & (~A[i]));

            int tmp3 = one & A[i];
            int tmp4 = two & (~A[i]);
            one = tmp1 | tmp2;
            two = tmp3 | tmp4;
        }
        return one;
    }
};
