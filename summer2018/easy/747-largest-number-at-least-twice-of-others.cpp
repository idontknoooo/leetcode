// My solution 10ms
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int idx1 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                idx1 = i;
            } else if(nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return (max1 >= 2*max2)? idx1 : -1;
    }
};
