/*
 * 将一个字符串分成两部分，X和Y两个部分，在字符串上定义反转的操作X^T，即把X的所有字符反转（如，X="abc"，那么X^T="cba"），那么我们可以得到下面的结论：(X^TY^T)^T=YX。显然我们这就可以转化为字符串的反转的问题了。
 *
 * 不是么?ok,就拿abcdef 这个例子来说，若要让def翻转到abc的前头，那么只要按下述3个步骤操作即可：
 * 1、首先分为俩部分，X:abc，Y:def；
 * 2、X->X^T，abc->cba， Y->Y^T，def->fed。
 * 3、(X^TY^T)^T=YX，cbafed->defabc，即整个翻转。
 */
#include <stdio.h>
#include <string>

using std::string;

void reverse(string &str, int front, int end)
{
    if (front < 0 || end > str.length() || str.length() <= 0) {
        return;
    }
    for (; front < end; ++front, --end) {
        int tmp = str[front];
        str[front] = str[end];
        str[end] = tmp;
    }
}

string rotate(string & in, int index)
{
    if (index >= in.length() || index <= 0 || in.length() <= 0) {

        return in;
    }
    reverse(in, 0, index - 1);
    reverse(in, index, in.length() - 1);
    reverse(in, 0, in.length() - 1);
    return in;
}

int main()
{
    string in = "defghiabc";
    printf("%s\n", in.c_str());
    rotate(in, 6);
    printf("%s\n", in.c_str());

}
