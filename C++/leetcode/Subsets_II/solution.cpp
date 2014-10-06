
class Solution {
public:
void help(vector<int> &input, int pre, int index,                                                                 
        vector<vector<int> > &ret, int ir) 
{
    // Print(ret);
    if (index >= input.size()) return;
    int s = ret.size();
    vector<int> t;
    if (input[index] != pre || index == 0) {
        t.push_back(input[index]);
        ret.push_back(t);
        for (int i = 0; i < ir; ++i) {
            vector<int> tmp = ret[i];
            tmp.push_back(input[index]);
            ret.push_back(tmp);
        }   
    }   
    for (int i = ir; i < s; ++i) {
        vector<int> tmp = ret[i];
        tmp.push_back(input[index]);
        ret.push_back(tmp);
    }   
    help(input, input[index], index + 1, ret, s); 
}
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        if (S.size() == 0) {
            return ret;
        }
        sort(S.begin(), S.end());
        help(S, 0, 0, ret, 0);
        vector<int> t;
        ret.push_back(t);
        return ret;
    }
};
