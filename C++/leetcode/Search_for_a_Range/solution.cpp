// 用两次二分查找分别找到头和尾
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        int front = 0;
        int end = n - 1;
        int f = -1;
        int e = -1;
        vector<int> ret;
        if (n <= 0) return ret;
        if (n == 1&&A[0] == target) {
            ret.push_back(0);
            ret.push_back(0);
            return ret;
        }
        if (n == 1&&A[0] != target) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }        
        while (front <= end) {
            int middle = (front + end) / 2;
            if (A[middle] < target) {
                front = middle + 1;
            }
            if (A[middle] > target) {
                end = middle - 1;
            }
            if (A[middle] == target) {
                if (middle >= 1 && A[middle] == A[middle - 1]) {
                    end = middle - 1;
                } else if (middle >= 1 && A[middle] != A[middle - 1]) {
                    f = middle;
                    break;
                } else if (middle == 0) {
                    f = middle;
                    break;
                }
            }
        }
        front = 0;
        end = n - 1;
        while (front <= end) {
            int middle = (front + end) / 2;
            if (A[middle] < target) {
                front = middle + 1;
            }
            if (A[middle] > target) {
                end = middle - 1;
            }
            if (A[middle] == target) {
                if (middle < n - 1 && A[middle] == A[middle + 1]) {
                    front = middle + 1;
                } else if (middle < n - 1 && A[middle] != A[middle + 1]) {
                    e = middle;
                    break;
                } else if (middle == n - 1) {
                    e = middle;
                    break;
                }
            }
        }
        ret.push_back(f);
        ret.push_back(e);
        return ret;
    }
};
