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

// 8ms
/* Output for 123

1 
1 2 
1 2 3 
1 3 
2 
2 3 
3 
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        
        helper(nums, res,t, 0);
        return res;
    }
    void helper(vector<int> & nums, vector<vector<int>>& res, vector<int> & t, int begin) {
        for(int a : t) cout << a << " ";
        cout << endl;
        res.push_back(t);
        for(int i=begin; i< nums.size(); i++) {
            t.push_back(nums[i]);
            helper(nums, res, t, i+1);
            t.pop_back();
        }   
    }   
    
};
