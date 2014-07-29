
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0 ) return 0;
        if (n == 1 || n == 2) return n;
        int one_step = 1, two_step = 2;
        for (int i = 3; i <= n; ++i) {
            int tmp = one_step + two_step;
            one_step = two_step;
            two_step = tmp;
        }
        return two_step;
    }
};
