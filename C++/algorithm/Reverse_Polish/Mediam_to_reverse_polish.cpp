//
// 中序表达式（普通常见的运算表达式）转换成逆波兰式
//
//

#include <stdio.h>
#include <string>
#include <stack>
#include <unordered_map>

using std::unordered_map;
using std::stack;
using std::string;

string MtoReverse(const string &str)
{
    if (str.size() == 0) return "";
    unordered_map<char, int> pre;
    pre['+'] = 0;
    pre['-'] = 0;
    pre['*'] = 1;
    pre['/'] = 1;
    stack<char> s1;
    stack<char> s2;
    for (int i = 0; i < str.size(); ++i) {
        if (pre.find(str[i]) != pre.end()) {
            while (!s2.empty() && pre[str[i]] <= pre[s2.top()]) {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(str[i]);
        } else {
            s1.push(str[i]);
        }
    }
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    string ret;
    while (!s2.empty()) {
        ret += s2.top();
        s2.pop();
    }
    return ret;
}

int main()
{
    string str = "a+b-c*x/b+a";
    printf("%s\n", MtoReverse(str).c_str());
    return 0;
}

