
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        vector<int> tmp;
        tmp.resize(n);
        for (int i = 0; i < n; ++i) {
            ret.push_back(tmp);
        }
        int count = 1;
        int x1 = 0, y1 = 0;
        int x2 = n - 1, y2 = n - 1;
        while (x1 <= x2 && y1 <= y2) {
            for (int i = x1; i <= x2; ++i ) {
                ret[y1][i] = count;
                ++count;
            }
            ++y1;
            if (y1 > y2) break;
            for (int i = y1; i <= y2; ++i) {
                ret[i][x2] = count;
                ++count;
            }
            --x2;
            if (x1 > x2) break;
            for (int i = x2; i >= x1; --i) {
                ret[y2][i] = count;
                ++count;
            }
            --y2;
            if (y1 > y2) break;
            for (int i = y2; i >= y1; --i) {
                ret[i][x1] = count;
                ++count;
            }
            ++x1;
            if (x1 > x2) break;
        }
        return ret;
    }
};
