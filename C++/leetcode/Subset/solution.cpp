/**
 *利用递归，从数字的第一位往后处理，处理到当前数字的时候将当前的数字加载之前的所有vector<int>里面所得到的结果
 *都加到之前的结果里面
 *
 */
class Solution {
public:

void Print(vector<vector<int> > &S)
{
    printf("[\n");
    for (int i = 0; i < S.size(); ++i) {
        printf(" [");
        for (int j = 0; j < S[i].size(); ++j) {
            printf("%d", S[i][j]);
            if (j < S[i].size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    printf("]\n");
}

void help(vector<int> &S, int index, vector<vector<int> >& ret)
{
    if (index > S.size() - 1) return;
    vector<vector<int > > tmp = ret;
    for (int i = 0; i < tmp.size(); ++i) {
        tmp[i].push_back(S[index]);
    }   
    for (int i = 0; i < tmp.size(); ++i) {
        ret.push_back(tmp[i]);
    }   
    vector<int> t;
    t.push_back(S[index]);
    ret.push_back(t);
    help(S, index + 1, ret);
}

vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > ret;
    help(S, 0, ret);
    vector<int> t;
    ret.push_back(t);
    return ret;
}
};
