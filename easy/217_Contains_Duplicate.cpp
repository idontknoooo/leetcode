class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // return nums.size() > set<int>(nums.begin(), nums.end()).size();  
        if (nums.empty()) { return false; }
        unordered_map<int,int> mp;
        for (int i : nums) {
            if (++mp[i] > 1) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        if(!nums.size()) return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; ++i){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};