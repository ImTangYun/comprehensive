
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        if (numbers.size() < 2) return ret;
        multimap<int, int> sort;
        for (int i = 0; i < numbers.size(); ++i) {
            sort.insert(pair<int, int>(numbers[i], i + 1));
        }
        int i = 0;
        multimap<int, int>::iterator iter1 = sort.begin();
        multimap<int, int>::iterator iter2 = sort.end();
        --iter2;
        while (iter2 != iter1) {
            if (iter1->first + iter2->first < target) {
                ++iter1;
            } else if (iter1->first + iter2->first > target) {
                --iter2;
            } else break;
        }
        int num1 = iter1->second,num2 = iter2->second;
        if (num1 > num2) swap(num1, num2);
        ret.push_back(num1);
        ret.push_back(num2);
        return ret;
    }
};
