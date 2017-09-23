class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int re = nums[0]; // current max
        int tmp = 0; // current sum, if negative, set to 0
        for(int num : nums)
        {
            tmp += num;
            re = max(re, tmp);
            tmp = max(tmp, 0);
        }
        return re;
    }
};
