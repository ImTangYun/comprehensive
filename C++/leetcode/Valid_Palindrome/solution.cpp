class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int i = 0, j = s.size() - 1;
        for (; i <= j; ) {
            while (i <= j && !((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a')
                ||  (s[i] <= '9' && s[i] >= '0'))) {
                ++i;
            }
            if (i > j) break;
            while (i <= j && !((s[j] <= 'Z' && s[j] >= 'A') || (s[j] <= 'z' && s[j] >= 'a') 
                ||  (s[j] <= '9' && s[j] >= '0'))) {
                --j;
            }
            if (i > j) break;
            if (((s[j] <= 'Z' && s[j] >= 'A') || (s[j] <= 'z' && s[j] >= 'a'))
                && ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a'))) {
                if (toupper(s[i]) != toupper(s[j])) return false;
                else {
                    ++i;
                    --j;
                }
            } else {
                if (s[i] != s[j]) return false;
                else {
                    ++i;
                    --j;
                }
            }
        }
        return true;
    }
};
