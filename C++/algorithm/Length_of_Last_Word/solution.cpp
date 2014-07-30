
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) return 0;
        int i = 0;
        while (s[i] != '\0' && s[i] == ' ') {
            ++i;
        }
        if (s[i] == '\0') {
            return 0;
        }
        int tmp = 0;
        int len1 = 0;
        while (s[i] != '\0') {
            while (s[i] != ' ' && s[i] != '\0') {
                ++len1;
                ++i;
            }
            tmp = len1;
            len1 = 0;
            if (s[i] == '\0') break;
            while (s[i] == ' ' && s[i] != '\0') {
                ++i;
            }
            if (s[i] == '\0') {
                break;
            }
        }
        return tmp;
    }
};
