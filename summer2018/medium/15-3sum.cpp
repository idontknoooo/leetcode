// 109ms solution beat 96%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break; // Never check number greater than 0, since all it's right gonna be greater than 0 too.
            if (k > 0 && nums[k] == nums[k - 1]) continue; // If meet same number, move to next

            int target = 0 - nums[k], left = k + 1, right = nums.size() - 1;
            while (left < right) {
                if (target == nums[left] + nums[right]) {
                    res.push_back({nums[k], nums[left], nums[right]});
                    // Eliminate repeat
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left, --right;
                } 
                else if (target > nums[left] + nums[right]) ++left; // Move right if current is too small
                else --right; // Otherwise move left
            }
        }
        return res;
    }
};
