
class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0) return 0;
        std::map<char, int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ret = 0;
        int index = s.length() - 1;
        int pre = mp[s[index]];
        for (; index >= 0; --index) {
            if (pre <= mp[s[index]]) {
                ret += mp[s[index]];
                pre = mp[s[index]];
            } else {
                ret -= mp[s[index]];
                pre = mp[s[index]];
            }
        }
        return ret;
    }
};
