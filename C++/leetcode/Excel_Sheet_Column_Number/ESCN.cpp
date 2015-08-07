// 其实就是进制转换，26进制转换成10进制
class Solution {
public:
    int titleToNumber(string s) {
        
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            ret = ret * 26 + (s[i] - 'A' + 1);
        }
        return ret;
    }
};
