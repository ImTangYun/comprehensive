
class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        return pow(x, n/2)*pow(x, n - n/2);
    }
};
