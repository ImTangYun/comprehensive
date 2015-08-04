class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> tmp;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_set<int>::iterator iter = tmp.find(nums[i]);
            if (iter != tmp.end()) {
                return true;
            }
            tmp.insert(nums[i]);
        }
        return false;
    }
};`
