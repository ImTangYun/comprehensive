class Solution {
public:
    int atoi(const char *str) {
        if (!str) return 0;
        bool flag = false;
        const char *p = str;
        while (*p != '\0' && *p == ' ') {
            ++p;
        }
        if (*p == '\0') return 0;
        if (*p == '-') {
            flag = true;
            ++p;
        } else if (*p == '+') {
            flag = false;
            ++p;
        }
        if (*p == '\0') {
            return 0;
        }
        long long tmp = 0;
        while (*p != '\0') {
            if (*p <= '9' && *p >= '0') {
                tmp *= 10;
                tmp += *p - '0';
                if (tmp > 0x7FFFFFFF) {
                    if (flag) return -2147483648;
                    return 2147483647;
                }
            } else {
                if (flag) return -(int)tmp;
                return (int)tmp;
            }
            ++p;
        }
        if (flag) return -(int)tmp;
        return (int)tmp;
    }
};
