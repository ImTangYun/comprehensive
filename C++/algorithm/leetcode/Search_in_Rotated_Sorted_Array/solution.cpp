class Solution {
public:
    int search(int A[], int n, int target) {
        int front = 0;
        int end = n - 1;
        while (front <= end) {
            int middle = (front + end) / 2;
            if (A[middle] == target) return middle;
            if (A[front] <= A[middle]) {
                if (A[front] <= target && target < A[middle])
                    end = middle - 1;
                else
                    front = middle + 1;
            } else {
                if (A[middle] < target && target <= A[end])
                    front = middle + 1;
                else
                    end = middle - 1;
            }
        }
        return -1;
    }
};
