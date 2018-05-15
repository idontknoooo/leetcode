class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size() / 2;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); ++i){
           if(!um[nums[i]]) {
               um[nums[i]] = 1;
           } else {
               um[nums[i]]++;
           }
           if(um[nums[i]]>size) return nums[i]; 
        }
    }
};
