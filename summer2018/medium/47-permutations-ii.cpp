// beat 95% 24ms
class Solution {
public:
    void recursion(vector<int> nums, int i, vector<vector<int> > &res) {
        if (i == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < nums.size(); k++) {
            if (i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            recursion(nums, i+1, res);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        recursion(nums,0,res);
        return res;
    }
};
