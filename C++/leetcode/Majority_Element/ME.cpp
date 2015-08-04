class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        if (nums.size() == 1) return ret;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (ret != nums[i + 1]) {
                --count;
                if (count < 0) {
                    ret = nums[i + 1];
                    count = 0;
                }
                
            } else {
                ++count;
            }
        }
        return ret;
    }
};
