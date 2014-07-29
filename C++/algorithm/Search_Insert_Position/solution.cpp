
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        while (right - left > 1) {
            int middle = (left + right) / 2;
            if (target > A[middle]) left = middle + 1;
            if (target < A[middle]) right = middle - 1;
            if (target == A[middle]) return middle;
        }
        if (left == right) {
            if (target > A[left]) return left + 1;
            if (target <= A[left]) return left;
        } else {
            if (target <= A[left]) return left;
            else if (target <= A[right]) return right;
            else return right + 1;
        }
    }
};
