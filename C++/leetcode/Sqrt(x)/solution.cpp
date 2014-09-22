
class Solution {
public:
    int sqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int ret = 0;
        int dif1 = 2;
        int dif2 = 3;
        int front = 0;
        int end = x + 1;
        while (dif1 > 0 || dif2 < 0) {
            ret = (front + end) / 2;
            if (ret == 0) ++ret;
            dif1 = ret - x/ret;
            dif2 = (ret + 1) - x/(ret + 1);
            if (dif1 > 0) {
                end = ret - 1;
            } else if (dif2 < 0) {
                front = ret + 1;
            } else if (dif1 == 0) {
                break;
            } else if (dif2 == 0) {
                ++ret;
                break;
            }
        }

        return ret;
    }
};
