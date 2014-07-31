// 利用一个栈来保存前括号，然后有后括号来时弹出栈顶来判断

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') S.push(s[i]);
            else if (s[i] == ')') {
                if (S.empty() || S.top() != '(') return false;
                else S.pop();
            }
            else if (s[i] == ']') {
                if (S.empty() || S.top() !=  '[') return false;
                else S.pop();
            }
            else if (s[i] == '}') {
                if (S.empty() || S.top() !=  '{') return false;
                else S.pop();
            }
        }
        if (!S.empty()) return false;
        return true;
    }
};
