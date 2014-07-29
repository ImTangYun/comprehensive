
class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        if (x < 0) {
            flag = false;
            x = -x;
        }
        char str[15];
        int i = 0;
        while (x) {
            int tmp = x % 10;
            str[i] = tmp + '0';
            x /= 10;
            ++i;
        }
        int ret = 0;
        for (int j = 0; j < i; ++j) {
            ret = ret*10 + str[j] - '0';
        }
        if (flag) return ret;
        else return -ret;
    }
};
