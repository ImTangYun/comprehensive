/**
 * 这道题的状态转移方程还是比較好写的，用ispart[i][j]代表s1贡献i长，s2贡献j长时
 * ，能不能形成s3的前i+j个字符。更新能够依照行或者列開始，s3的前i+j个字符，
 * 能够是((i-1)+1)+j构成，也能够是i+((j-1)+1)构成，
 * 这取决于当前的这个字符s3[i+j-1]跟s1[i-1]和s2[j-1]是否相等，或的关系就能够解决这个问题。
 * 边界条件也非常好确定，就是当仅仅有一个string參与构造时的情况，注意一旦有不相等的字符，那么后面的全都白搭。
 */


#include <stdio.h>
#include <string>

using std::string;

void Print(bool** p, int x, int y)
{
    if (x <= 0 || y <= 0) return;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j)
            printf("%d  ", p[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool solution(string s1, string s2, string s3)
{
    int len1 = s1.length();
    int len2 = s2.length();
    bool **p = new bool*[len1 + 1];
    for (int i = 0; i <= len1; ++i) {
        p[i] = new bool[len2 + 1]();
    }
    p[0][0] = 1;
    for (int i = 0; i < len1; ++i) {
        if (s1[i] != s3[i]) break;
        p[i + 1][0] = true;
    }
    for (int i = 0; i < len2; ++i) {
        if (s2[i] != s3[i]) break;
        p[0][i + 1] = true;
    }
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            p[i][j] = (s3[i + j - 1] == s1[i - 1] && p[i - 1][j])
                || (s3[i + j - 1] == s2[j - 1] && p[i][j - 1]);
        }
    }
    bool ret = p[len1][len2];
    for (int i = 0; i <= len1; ++i) {
        delete [] p[i];
    }
    delete [] p;
    return ret;
}

int main()
{
    string s1 = "asdfg";
    string s2 = "wdg";
    string s3 = "awsddfgg";
    printf("%d\n", solution(s1, s2, s3));
    return 0;
}

