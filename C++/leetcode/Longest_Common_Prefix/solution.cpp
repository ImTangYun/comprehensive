
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len1 = strs.size();
        if (len1 == 0) return "";
        int min = strs[0].length();
        for (int i = 0; i < len1; ++i) {
            if (strs[i].length() == 0) return "";
            else min = min <= strs[i].length()?min:strs[i].length();
        }
        int length = 0;
        for (int i = 0; i < min; ++i) {
            char alpha = strs[0][i];
            for (int j = 0; j < len1; ++j) {
                if (strs[j][i] != alpha) {
                    return strs[0].substr(0, length);
                }
            }
            ++length;
        }
        return strs[0].substr(0, length);
    }
};
