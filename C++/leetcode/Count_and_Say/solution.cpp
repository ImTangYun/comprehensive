
class Solution {
public:
string countAndSay(int n) {
    string s = "1";
    string s1;
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        //printf("s:%s s1:%s\n", s.c_str(), s1.c_str());
        if (!flag) {
            int count = 1;
            char alpha = s[0];
            s1.clear();
            int j = 1;
            for (; j < s.size(); ++j) {
                if (s[j] == alpha) {
                    ++count;
                } else {
                    s1 += '0' + count;
                    s1 += alpha;
                    alpha = s[j];
                    count = 1;
                }
            }
            s1 += '0' + count;
            s1 += alpha;
        } else {
            int count = 1;
            char alpha = s1[0];
            s.clear();
            int j = 1;
            for (; j < s1.size(); ++j) {
                if (s1[j] == alpha) {
                    ++count;
                } else {
                    s += '0' + count;
                    s += alpha;
                    alpha = s1[j];
                    count = 1;
                }
            }
            s += '0' + count;
            s += alpha;                
        }
        //printf("s:%s s1:%s\n", s.c_str(), s1.c_str());
        flag = !flag;
    }
    if (flag) return s1;
    else return s;
}
};
