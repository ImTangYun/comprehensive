/**
 *直接用除数去一个一个加，直到被除数被超过的话，会超时。
  
 解决办法每次将被除数增加1倍，同时将count也增加一倍，如果超过了被除数，那么用被除数减去当前和再继续本操作。

 */

class Solution {
public:
long long doubled(long long x)                                                                                    
{
    return x + x;
}

int divide(int x1, int y1) 
{
    long long x, y;
    bool flag1;
    bool flag2;
    if (x1 >= 0) {
        flag1 = false;
        x = (long long)x1; 
    } else {
        flag1 = true;
        x = -(long long)x1;
    }   
    if (y1 >= 0) {
        y = (long long)y1; 
        flag2 = false;
    } else {
        y = -(long long)y1;
        flag2 = true;
    }
    if (x < y) return 0;
    long long pre = y, next = y;
    long long count  = 1;
    long long ret = 0;
    long long left = x;
    while (left >= y) 
    {
        pre = next;
        next = doubled(next);
        if (left < next) {
            left -= pre;
            ret += count;
            pre = y;
            next = y;
            count = 1;
            continue;
        }
        count = doubled(count);
        if (left == next) {
            ret += count;
            break;
        }
    }
    if (flag2^flag1) return -(int)ret;
    return (int)ret;
}
};
