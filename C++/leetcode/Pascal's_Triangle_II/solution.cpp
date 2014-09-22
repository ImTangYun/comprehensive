
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        vector<int> tmp;
        ret.push_back(1);
        if (rowIndex == 0) return ret;
        bool flag = false;
        for (int i = 1; i <= rowIndex; ++i) {
            if (!flag) {
                tmp.push_back(1);
                for (int j = 1; j < i; ++j) {
                    tmp.push_back(ret[j - 1] + ret[j]);
                }
                tmp.push_back(1);
                ret.clear();
            } else {
                ret.push_back(1);
                for (int j = 1; j < i; ++j) {
                    ret.push_back(tmp[j - 1] + tmp[j]);
                }
                ret.push_back(1);
                tmp.clear();                
            }
            flag = !flag;
        }
        if (flag) return tmp;
        else return ret;
    }
};
