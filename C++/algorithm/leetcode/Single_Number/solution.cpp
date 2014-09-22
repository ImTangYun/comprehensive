
class Solution {
public:
    int singleNumber(int A[], int n) {
        int num = 0;
        for (int i = 0; i < n; ++i) {
            num ^= A[i];
        }
        return num;
    }
};
