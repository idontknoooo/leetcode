class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> um;
        int tmp = 0;
        for(int i = 0; i < nums.size(); ++i){

            tmp = target - nums[i]; 
            
            if(um.find(tmp) != um.end())
               return {i, um[tmp]};
            
            um[nums[i]] = i; 
        }

        return {};           
    }
};
