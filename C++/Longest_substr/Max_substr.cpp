//
//
//动态规划有一个经典问题是最长公共子序列，但是这里的子序列不要求连续，如果要求序列是连续的，我们叫公共子串，那应该如何得到这个串呢？
//
//
//最简单的方法就是依次比较，以某个串为母串，然后生成另一个串的所有长度的子串，依次去母串中比较查找，这里可以采用先从最长的子串开始，减少比较次数，但是复杂度依然很高！
//
//
//然后重新看一下这个问题，我们建立一个比较矩阵来比较两个字符串str1和str2
//
//
//定义 lcs(i,j) ，当str1[i] = str2[j]时lcs(i,j)=1,否则等于0。
//
//example:
//
//str1 = "bab"
//
//str2 = "caba"
//
//
//建立矩阵
//
//--b  a  b
//
//c 0  0  0
//
//a 0  1  0
//
//b 1  0  1
//
//a 0  1  0
//
//
//连续i子串的特点就是如果str1[i]和str2[j]是属于某公共子串的最后一个字符，那么一定有str1[i]=str2[j] && str1[i-1] = str2[j-1]，从矩阵中直观的看，就是由“1”构成的“斜线”代表的序列都是公共子串，那么最长公共子串肯定就是斜线“1”最长的那个串。
//
//那么现在问题就可以转化了，只要构造出如上的一个矩阵，用n^2的时间就可以得到矩阵，然后再到矩阵中去寻找最长的那个“1”构成的斜线就可以了！那么，现在又有了新的问题？如何快速的找到那个“1”构成的最长斜线呢？
//
//采用DP的思想，如果str1[i] = str2[j]，那么此处的包含str1[i] 和 str2[j]公共子串的长度必然是包含str1[i-1]和str2[j-1]的公共子串的长度加1，那么现在我们可以重新定义lcs(i,j)，即是lcs(i,j) = lcs(i-1,j-1) + 1，反之，lcs(i,j) = 0。那么上面的矩阵就变成了如下的样子：
//
//--b  a  b
//
//c 0  0  0
//
//a 0  1  0
//
//b 1  0  2
//
//a 0  2  0
//
//现在问题又变简单了，只需要花n^2的时间构造这样一个矩阵，再花n^2的时间去找到矩阵中最大的那个值，对应的就是最长公共子串的长度，而最大值对应的位置对应的字符，就是最长公共子串的最末字符。
//
//
//算法还可以改进，我们可以将查找最大长度和对应字符的工作放在构造矩阵的过程中完成，一边构造一边记录当前的最大长度和对应位置，这样就节省了n^2的查找时间。
//
//空间上也可以做改进，如果按照如上的方式构造，我们发现，当矩阵的第i+1行的值计算完成后，第i行的值就没有用了，即便是最长的长度出现在第i行，我们也已经用变量记录下来了。因此，可以将矩阵缩减成一个向量来处理，向量的当前值对应第i行，向量的下一个循环后的值对应第i+1行。
//
#include <stdio.h>
#include <string>
using std::string;

void Print(int **p, int x, int y)
{
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d  ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
string max_substr(string s1, string s2)
{
    string ret;
    if (s1.size() == 0 || s2.size() == 0) return ret;
    int **p = new int*[s1.size()];
    for (int i = 0; i < s1.size(); ++i) {
        p[i] = new int[s2.size()]();
    }
    int max_i = 0, max_j = 0;
    int max = 0;
    Print(p, s1.size(), s2.size());
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0) p[i][j] = 1;
                else p[i][j] = p[i - 1][j - 1] + 1;
                if (p[i][j] > max) {
                    max = p[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }
    Print(p, s1.size(), s2.size());
    ret = s1.substr(max_i - max + 1, max);
    for (int i = 0; i < s1.size(); ++i) {
        delete [] p[i];
    }
    delete [] p;
    return ret;
}

int main()
{
    string s1 = "abceddd";
    string s2 = "dfdfdfdfabceddd";
    string s = max_substr(s1, s2);
    printf("%s\n", s.c_str());
    return 0;
}
