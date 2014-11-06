/*
 *主要思想是动态规划：
 * 1.先判断i = 0~max(m,n)之间的连续满足条件的i = am + bn的个数是否为
 * min(m, n),同时记录进一个表格，如果是那么返回0；
 * 2.如果上面条件不成立，进行本步骤，从i = max（m,n）~ +00判断是否有连续
 * min(m,n)个数是满足条件的，同时记录近表格，如果满足则返回i-min(m,n)+1
 * 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using std::vector;

inline int max(int x, int y)
{
    if (x > y) return x;
    return y;
}

inline int min(int x, int y)
{
    if (x > y) return y;
    return x;
}

int x(int m, int n)
{
    vector<bool> tmp;
    int mm = max(m, n);
    tmp.resize(mm);
    int count = 0;
    int i = 0;
    int xx = min(m, n);
    for (; i < mm; ++i) {
        if (i % m == 0 || i % n == 0) {
            ++count;
            if (count >= xx) return i;
            tmp[i] = true;
        } else {
            count = 0;
            tmp[i] = false;
        }
    }
    while (true) {
        bool ret = tmp[i - m] || tmp[i - n];
        if (ret) {
            ++count;
            if (count >= xx) return i - xx + 1;
        } else {
            count = 0;
        }
        tmp.push_back(ret);
        ++i;
    }
}

int main(int args, char** argv)
{
    if (args != 3) {
        printf("Usage: %s num1 num2\n", argv[0]);
        exit(0);
    }
    printf("%d\n", x(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

