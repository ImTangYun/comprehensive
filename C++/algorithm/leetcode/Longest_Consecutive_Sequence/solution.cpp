
//遍历数组存入hash表，从hash表里面取值想其两边
//查询相邻的值， 每次与当前最长的连续值比较若
//大于当前值则替换(查询过的数字都从hash表删除)
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int len = num.size();
        if (len <= 1) return len;
        set<int> x;
        for (int i = 0; i < len; ++i) {
            x.insert(num[i]);
        }
        set<int>::iterator iter = x.begin();
        int max = 1;
        int front = *iter;
        int end = *iter;
        x.erase(iter);
        int tmp = 1;
        while (x.size() > 0) {
            set<int>::iterator iter1 = x.find(front - 1);
            set<int>::iterator iter2 = x.find(end + 1);
            if (iter1 != x.end()) {
                ++front;
                ++tmp;
                x.erase(iter1);
            }
            if (iter2 != x.end()) {
                ++end;
                ++tmp;
                x.erase(iter2);
            }
            if (x.size() == 0) {
                max = max > tmp?max:tmp;                
            }
            if ((iter1 == x.end() && iter2 == x.end()) && x.size() != 0) {
                max = max > tmp?max:tmp;
                iter = x.begin();
                front = *iter;
                end = *iter;
                x.erase(iter);
                tmp = 1;
            }
        }
        return max;
    }
};
