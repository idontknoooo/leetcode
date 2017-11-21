class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            if (i%2==0)
                a = max(a+nums[i], b); // current sum vs adjacent previous sum, if adj_pre_sum > cur_sum, should choose adj_pre_sum, because it has the potential to add 1 value after 'cur' to make it even bigger
            else
                b = max(a, b+nums[i]);
        }
        return max(a, b);
    }
};