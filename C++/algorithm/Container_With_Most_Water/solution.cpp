
class Solution {
public:
    int min(int x, int y) {
        if (x < y) return x;
        return y;
    }
    int maxArea(vector<int> &height) {
        int front = 0;
        int end = height.size() - 1;
        if (end <= 0) return 0;
        int maxarea = min(height[front], height[end])*(end - front);
        while (front < end) {
            int f = height[front];
            int e = height[end];
            if (height[front] <= height[end]) {
                ++front;
                while (height[front] <= f && front < end) ++front;
                if (front >= end) break;
                else {
                    int tmp = min(height[front], height[end])*(end - front);
                    maxarea = maxarea>tmp?maxarea:tmp;
                }
            } else {
                --end;
                while (height[end] <= e && front < end) --end;
                if (front >= end) break;
                else {
                    int tmp = min(height[front], height[end])*(end - front);
                    maxarea = maxarea>tmp?maxarea:tmp;
                }                
            }
        }
        return maxarea;
    }
};
