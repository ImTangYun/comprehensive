
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        if (prices.size() <= 1) return ret;
        for (int i = 1; i < prices.size(); ++i) {
            int tmp = prices[i] - prices[i - 1];
            if (tmp > 0) {
                ret += tmp;
            }
        }
        return ret;
    }
};
