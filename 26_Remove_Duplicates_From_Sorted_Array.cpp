class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
			// Count repeat
            if(nums[i] == nums[i-1]) count++;
			// Overwrite repeat
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;
    }
};
// Final vector will have all unique member and bunch of empty space at the end
