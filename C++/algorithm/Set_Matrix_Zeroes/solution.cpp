/**
 *基本原理：用每第一行或者每第一列来保存本列/行的状态
 *先比阿里第一列和第一行，保存第一列和第一行是否需要滞空的标记
 *例如：第一次遍历matrix[i][j] == 0 那么我就把matrix[0][j]和matrix[i][0]设置为零
 *第二次遍历的时候，先不处理第一行和第一列
 *最后分别处理第一行和第一列
 *时间复杂度mn空间复杂度O(1)
 */


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int len1 = matrix.size();
        if (len1 == 0) return;
        int len2 = matrix[0].size();
        int r = matrix[0][0];
        int c = r;
        for (int i = 0; i < len1; ++i) {
            if (matrix[i][0] == 0) {
                r = 0;
                break;
            }
        }
        for (int i = 0; i < len2; ++i) {
            if (matrix[0][i] == 0) {
                c = 0;
                break;
            }
        }
        for (int i = 1; i < len1; ++i) {
            for (int j = 1; j < len2; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < len1; ++i)
            for (int j = 1; j < len2; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        if (r == 0) {
            for (int i = 0; i < len1; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (c == 0) {
            for (int i = 0; i < len2; ++i) {
                matrix[0][i] = 0;
            }
        }
    }
};
