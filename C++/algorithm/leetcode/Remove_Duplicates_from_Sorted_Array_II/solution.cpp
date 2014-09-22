
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int jump = 0;
        if (n <= 1) return n;
        int c = A[0];
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (c != A[i]) {
                c = A[i];
                count = 0;
                A[i - jump] = A[i];
                continue;
            } else {
                ++count;
            }
            if (count <= 1) {
                A[i - jump] = A[i];
                continue;
            }
            if (count > 1) {
                ++jump;
                A[i - jump] = A[i];
            }
        }
        return n - jump;
    }
};
