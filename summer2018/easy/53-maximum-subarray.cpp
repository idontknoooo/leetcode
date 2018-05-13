class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], cur = 0;
        for(int i = 0; i < nums.size(); ++i){
            cur += nums[i];
            if(maxSum < cur) maxSum = cur;
            if(cur <= 0)
               cur = 0;
        }
        return maxSum;
    }
};
