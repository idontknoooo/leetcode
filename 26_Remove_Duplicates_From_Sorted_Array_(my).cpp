class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin()+i-1);
                i--;
            }
        }
        return nums.size();
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return nums.size();
    }
};
