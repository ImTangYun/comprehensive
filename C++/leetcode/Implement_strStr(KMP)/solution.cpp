class Solution {
public:
    void next(const char* str, int **n, int len)
    {
        if (len <= 0) {
            *n = NULL;
            return;
        }
        *n = new int[len];
        n[0][0] = -1;
        if (len == 1) {
            return; 
        }
        n[0][1] = 0;
        for (int i = 2; i < len; ++i) {
            int j = (*n)[i - 1];
            while (j >= 0 && str[i - 1] != str[j]) {
                j = (*n)[j];
            }
            (*n)[i] = j + 1;
        }
    }
    char *strStr(char *haystack, char *needle) {
        if (haystack != NULL && *needle == '\0') return haystack;
        int *n;
        int len = strlen(needle);
        if (len == 0) return NULL;
        int len1 = strlen(haystack);
        next(needle, &n, len);
        int j = 0;
        for (int i = 0; i < len1; ++i) {
            while (j >= 0 && haystack[i] != needle[j]) {
                j = n[j];
            }
            if (j < 0) {
                ++j;
                ++i;
            }
            if (i >= len1) return NULL;
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == len) {
                return haystack + i - len + 1;
            }
        }
        delete [] n;
        return NULL;
    }
};
