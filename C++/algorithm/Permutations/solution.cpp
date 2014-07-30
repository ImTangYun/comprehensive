

class Solution {
public:
    void help(vector<vector<int> > &ret, vector<int> &num, int position)
    {
        if (position == num.size()) {
            ret.push_back(num);
            return;
        }
        for (int i = position; i < num.size(); ++i) {
            swap(num[position], num[i]);
            help(ret, num, position + 1);
            swap(num[position], num[i]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        help(ret, num, 0);
        return ret;
    }
};
