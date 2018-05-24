// my solution 42ms
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_one = 0;
        int i = 0, j = 0;
        for(; i < nums.size();){
            if(nums[i]==1){
                ++i;
            } else {
                if(i - j > max_one) max_one = i - j;
                ++i;
                j = i;
            }
        }
        return max(max_one, i-j);
    }
};


// 36ms
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int count = 0;
        int maxCount = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1) count++;
            else
            {
                if(count > maxCount) maxCount = count;
                count = 0;
            }
        }
        
        if(count > maxCount) maxCount = count;
        
        return maxCount;
    }
};
