
class Solution {
public:

    int uniquePaths(int m, int n) {
        int *array = new int[m*n];
        for (int i = 0; i < m; ++i) {
            array[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            array[m*i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                array[i*m + j] = array[(i - 1)*m + j] + array[i*m + j - 1];
            }
        }
        int ret = array[m*n - 1];
        delete [] array;
        return ret;
    }
};
