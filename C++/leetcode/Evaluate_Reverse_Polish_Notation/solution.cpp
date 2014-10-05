// 题目大意：给定一个逆波兰表达式，求该表达式的值
// 思路：由于逆波兰表达式本身不需要括号来限制哪个运算该先进行，因此可以直接利用栈来模拟计算：遇到操作数直接压栈，碰到操作符直接取栈顶的2个操作数进行计算（注意第一次取出来的是右操作数），然后再把计算结果压栈，如此循环下去。最后栈中剩下的唯一一个元素便是整个表达式的值

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> tmp;
        for (int i = 0; i < tokens.size(); ++i) {
            if (!((tokens[i] == "+") || (tokens[i] == "-")
                || (tokens[i] == "*") || (tokens[i] == "/"))) {
                tmp.push(atoi(tokens[i].c_str()));
            } else {
                int a = tmp.top();
                tmp.pop();
                int b = tmp.top();
                tmp.pop();
                if (tokens[i] == "+") {
                    tmp.push(a + b);
                } else if (tokens[i] == "-") {
                    tmp.push(b - a);
                } else if (tokens[i] == "*") {
                    tmp.push(a * b);
                } else if (tokens[i] == "/") {
                    tmp.push(b / a);
                }
            }
        }
        return tmp.top();
    }
};
