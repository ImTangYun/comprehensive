
class Solution {
public:
    double pow(double x, int n) {
 
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        bool flag = false;
        if (n < 0) {
            n = -n;
            flag = true;
        }
        double p = pow(x,n/2);
        double ret;
        if (n%2 == 0) {
            ret = p*p;
        } else {
            ret = p*p*x;
        }
        if (!flag)
            return ret;
        else
            return 1/ret;
    }
};
