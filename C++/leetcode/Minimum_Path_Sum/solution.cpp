
class Solution {
public:
    int min(int x, int y)
    {
        if (x > y) return y;
        return x;
    }
    int minPathSum(vector<vector<int> > &grid) {
        int len1 = grid.size();
        if (len1 == 0) {
            return 0;
        }
        int len2 = grid[0].size();
        if (len2 == 0) {
            return 0;
        }
        int *array = new int[len1*len2];
        array[0] = grid[0][0];
        for (int i = 1; i < len1; ++i) {
            array[i*len2 + 0] = array[(i - 1)*len2 + 0] + grid[i][0];
        }
        for (int i = 1; i < len2; ++i) {
            array[i] = array[i - 1] + grid[0][i];
        }
        for (int i = 1; i < len1; ++i) {
            for (int j = 1; j < len2; ++j) {
                array[i*len2 + j] = min(array[(i - 1)*len2 + j], array[i*len2 + j - 1]) + grid[i][j];
            }
        }
        int ret = array[len1*len2 - 1];
        delete [] array;
        return ret;
    }
};
