
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        stack<char> s;
        int flag = 0;
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 && j >= 0) {
            int a_i = a[i] - '0';
            int b_j = b[j] - '0';
            s.push(((a_i + b_j + flag) % 2) + '0');            
            flag = (a_i + b_j + flag) / 2;
            --i;
            --j;
        }
        while (i >= 0) {
            int a_i = a[i] - '0';
            s.push(((a_i + flag) % 2) + '0');
            flag = (a_i + flag) / 2;
            --i;
        }
        while (j >= 0) {
            int b_j = b[j] - '0';
            s.push(((b_j + flag) % 2) + '0');
            flag = (b_j + flag) / 2;
            --j;
        }
        if (flag == 1) s.push('1');
        while (!s.empty()) {
            ret += s.top();
            s.pop();
        }
        return ret;
    }
};
