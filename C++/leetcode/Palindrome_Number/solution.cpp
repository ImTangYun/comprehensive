
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int tmp = x;
        string s;
        while (tmp) {
            int m = tmp % 10;
            s += static_cast<char>('0' + m);
            tmp /= 10;
        }
        bool flag = true;
        int front = 0, end = s.length() - 1;
        while (front <= end) {
            if (s[front] != s[end]) {
                flag = false;
                break;
            }
            ++front;
            --end;
        }
        return flag;
    }
};
