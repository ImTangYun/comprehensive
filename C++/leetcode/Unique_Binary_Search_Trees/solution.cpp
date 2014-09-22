
class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int *array = new int[n + 1];
        array[0] = 1;
        array[1] = 1;
        array[2] = 2;
        for (int i = 3; i <= n; ++i) {
            int tmp = 0;
            for (int j = 0; j < i; ++j) {
                tmp += array[j] * array[i - j - 1];
            }
            array[i] = tmp;
        }
        int ret = array[n];
        delete [] array;
        return ret;
    }
};
