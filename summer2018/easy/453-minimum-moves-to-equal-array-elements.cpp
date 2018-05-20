class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(), nums.end());
        int min_val = nums[0];
        int count = 0;
        for(int i = 0;  i < nums.size(); ++i){
            if(min_val != nums[i]) count += nums[i]-min_val;
        }
        return count;
    }
};


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum, min;
        sum = nums[0];
        min = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
            if(min > nums[i])   min = nums[i];
        }
        return sum - nums.size() * min;
    }
};
