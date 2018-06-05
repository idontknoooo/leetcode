// 8ms
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> res;
        dfs(nums, 0, curr, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res) {
        int len = nums.size(); if (index == len) { res.push_back(curr); return; }
        
        for (int i = index; i < len; ++i) {
            if (i == index || nums[i-1] != nums[i])
            {
                curr.push_back(nums[i]);
                dfs(nums, i+1, curr, res);
                curr.pop_back();
            }
        }
        dfs(nums, len, curr, res);
    }
};


// 8ms
class Solution {
public:
    void subsetsWithDup(vector<int>& nums, vector<int>& tmp, vector<vector<int>> &result, int index) {
        if (index == nums.size()) {
            return ;
        }
        for (int i = index; i < nums.size(); i++) {
            if (i == index || (i > index && nums[i] != nums[i - 1])) {
                tmp.push_back(nums[i]);
                result.push_back(tmp);
                subsetsWithDup(nums, tmp, result, i + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> result;
        result.push_back(tmp);
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, tmp, result, 0);
        return result;
    }
};
