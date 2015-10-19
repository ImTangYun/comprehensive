/*
 * 思路：
 *
 * 1、首先证明当 n=2^k 时，存在时间复杂度为O(N),空间复杂度为O(1)的算法。
 *
 * 2、其次证明对任意n，存在时间复杂度为O(N),空间复杂度为O(1)的算法。
 *
 * 证明：
 *
 * 1、当 n=2^k 时，存在时间复杂度为O(N),空间复杂度为O(1)的算法。
 *
 * 首先，从新编号，从“a1 a2 a3 .. an b1 b2 b3 .. bn” 到“0, 1, ... ，2^k-1， 2^k，... ，2^(k+1)-1”。
 *
 * 设某元素原来的下标为i，变换后的下标为j，则有：j=(2*i)%(2*n-1)。 例如：1-->2 (a2-->a3)， 2-->4 (a3-->a5)。
 *
 * 然后，从1，3，...， n-1依次执行变换。例如n=8，则有：
 *
 * 1-->2-->4-->8-->1
 *
 * 3-->6-->12-->9-->3
 *
 * 5-->10-->5
 *
 * 7-->14-->13-->11-->7
 *
 * 设从i(i=2*k+1)开始变换的一组下标的集合为Si，则可以证明，Si∩Sj=空集，且 ∪Si=全集。
 *
 * 所以，该变换的时间复杂度为O(N),空间复杂度为O(1)的算法。
 *
 * 2、对任意n，存在时间复杂度为O(N),空间复杂度为O(1)的算法。
 *
 * 对任意n，有n=∑ck*x^k，其中ck=0或1。
 *
 * 因此，可以采用对任意ck=1的情况：
 *
 * 首先，做整体移位，两个2^k连续块放在一起(采用翻转法[1]，时间复杂度为O(N),空间复杂度为O(1))；
 *
 * 其次，对两个2^k连续块采用上面的算法；
 *
 * 然后，对剩余部分再采取前两步的方法，直到k=1。
 *
 * 例如n=11，则有:
 *
 * 第一次：
 *
 * 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21
 *
 * 变为 0,1,2,3,4,5,6,7,11,12,13,14,15,16,17,18,  8,9,10,19,20,21
 *
 * 然后 0,11,1,12,2,13,3,14,4,15,5,16,6,17,7,18,  8,9,10,19,20,21
 *
 * 第二次：
 *
 * 0,1,2,3,4,5,6,7,11,12,13,14,15,16,17,18,  8,9,10,19,20,21
 *
 * 变为 0,1,2,3,4,5,6,7,11,12,13,14,15,16,17,18,  8,9,19,20,  10,21
 *
 * 然后 0,11,1,12,2,13,3,14,4,15,5,16,6,17,7,18,  8,19,9,20,  10,21
 *
 * 证明对任意n该方法的时间复杂度为O(N)，有两种证明方法：
 *
 * 1、采用master theorem[2]，可直接证明。
 *
 * 2、到n=2^k-1时，该算法的时间复杂度最大。因此，只需证明此时的时间复杂度为O(N)。
 *
 * 利用等比数列，可以证明此结论。
 *
 * 算法与证明描述结束。
 *
 * [1] 编程之美。问题2.17。
 *
* [2] 算法导论。定理4.1
*/
#include <stdio.h>
#include <string>

using namespace std;

string cross_str(string &str)
{
    if (str.length() <= 2) {
        return str;
    }
    char tmp = str[str.length() / 2];
    int i = str.length() / 2;
    while (i != 1) {
        printf("%d\n", i);
        str[i] = str[(i + (i % 2) * (str.length() - 1)) / 2];
        i = (i + (i % 2) * (str.length() - 1)) / 2;
    }
    str[1] = tmp;
    return str;
}

int get_real_index(const int &origin_index, const int &half_size)
{
    if (origin_index % 2 == 0) {
        return origin_index / 2;
    }
    return half_size + origin_index / 2;
}

string cross_str1(string &str)
{
    if (str.length() <= 2) {
        return str;
    }
    int half_size = str.length() / 2;
    char tmp = str[half_size];
    int i = half_size;
    while (i != 1) {
        printf("%d\n", i);
        int j = get_real_index(i, half_size);
        str[i] = str[j];
        i = j;
    }
    str[1] = tmp;
    return str;
}

void print_str(string str)
{
    for (int i = 0; i < str.length(); ++i) {
        printf(" %c", str[i]);
    }
    printf("\n");
}

int main()
{
    string str = "abcdefabcdef";
    print_str(str);
    cross_str1(str);
    print_str(str);
    return 0;
}

