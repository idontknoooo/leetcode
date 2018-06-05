// 6ms 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       
        
        int cnt = 0;
        int n = nums.size();
        int sub = pow(2, n);
        vector<vector<int>> result(sub, vector<int>());
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < sub; j++)
            {
                if(j>>i & 1)
                {
                    result[j].push_back(nums[i]);
                }
            }
        }
        

        return result;
    }
    
};
