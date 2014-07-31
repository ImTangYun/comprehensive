方法一(动态规划(o（n^2）))：

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        int front = 0;
        int max = 0;
        int index = 1;
        while (index < s.length()) {
            for (int i = front; i < index; ++i) {
                if (s[i] == s[index]) {
                    front = i + 1;
                }
            }
            int length = index - front + 1;
            max = (max > length)?max:length;
            ++index;
        }
        return max;
    }
};
方法二（动态规划+hash （o(n)））：


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        int front = 0;
        int max = 0;
        int index = 1;
        unordered_map<char, int> comp;
        comp[s[0]] = 0;
        while (index < s.length()) {
            unordered_map<char, int>::iterator iter = comp.find(s[index]);
            if (iter == comp.end()) {
                comp[s[index]] = index;
            } else {
                front = iter->second + 1;
                comp.erase(iter);
            }
            int length = index - front + 1;
            max = (max > length)?max:length;
            ++index;
        }
        return max;
    }
};
