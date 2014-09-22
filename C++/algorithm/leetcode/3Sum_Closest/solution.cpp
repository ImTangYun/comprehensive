// 思路是，先对数组排序然后一个指针遍历数组，另外两个指针分别从前后向中间移动查找最接近的和
class Solution {
public:
    int dis(int x, int target) {
        int ret = x - target;
        if (ret >= 0) return ret;
        return -ret;
    }
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() <= 0) return target;
        int ret = 3*num[0];
        multimap<int, int> se;
        int tdis = 9999999;
        for (int i = 0; i < num.size(); ++i) {
            se.insert(pair<int, int>(num[i], i));
        }
        multimap<int, int>::iterator iter1 = se.begin();
        multimap<int, int>::iterator iter2 = se.end();
        --iter2;
        for (int i = 0; i < num.size(); ++i) {

            while (iter1 != iter2) {
                if (iter1->second == i) {
                    ++iter1;
                    continue;
                }
                if (iter2->second == i) {
                    --iter2;
                    continue;
                }
                int tmp = iter1->first + iter2->first + num[i];
                int di = dis(tmp, target);
                if (di < tdis) {
                    tdis = di;
                    ret = tmp;
                }
                if (tmp > target) {
                    --iter2;
                } else if (tmp < target){
                    ++iter1;
                } else return target;
            }

            iter1 = se.begin();
            iter2 = se.end();
            --iter2;
        }
        return ret;
    }
};

