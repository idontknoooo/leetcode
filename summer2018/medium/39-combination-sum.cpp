class Solution {
private:
    vector<vector<int>> res;
public:
    //从[start, ...],可以一直重复选择，但不允许回头。以免结果重复。
    void dfs(vector<int>& candidates, vector<int>& temp, int target, int start){
       
        if (0 == target){
            res.push_back(temp);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++){
            if (candidates[i] <= target){
                temp.push_back(candidates[i]);
                dfs(candidates, temp, target - candidates[i], i);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, temp, target, 0);
        return res;
    }
};



// 15ms beat 85%
class Solution {
private:
    void dfs(int index, int target, vector<int>&nums, vector<int>& chosen, vector<vector<int>>& st){
        if(target == 0){
            st.push_back(chosen);
            return;
        }
        if(target < 0 || index >= nums.size()){
            return;
        }
        for(int i=index; i<nums.size(); ++i){
            int n = nums[i];
            chosen.push_back(n);
            target -= n;
            dfs(i, target,nums,chosen,st);
            target += n;
            chosen.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> chosen;
        dfs(0,target, candidates, chosen,ret);
        return ret;
    }
};


