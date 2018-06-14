// 2ms
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n ==1) return nums[0];
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
    int robber(vector<int>&nums, int begin, int end){
        int pre = 0, cur = 0;
        for(int i = begin; i<= end; i++){
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};

// 4ms
class Solution {
public:
    int rob(vector<int>& nums) {
        int reVal;
        size_t numssize = nums.size();
        if(numssize == 0)
            reVal=0;
        else if(numssize == 1)
            reVal = nums[0];
        else
        {
    // b1 marks the last maxamout with the first house robbed, 
    // while b0 marks the last maxamout with the first house escaped.
            int a0=0,b0=nums[1],a1=nums[0],b1=nums[0],temp;
            for(size_t i=2;i<numssize;i++)
            {
                temp = b0;
                b0= max(a0+nums[i],b0);
                a0= temp;
                
                temp = b1;
                b1 = max(a1+nums[i],b1);
                a1 = temp;
            }
            reVal = max(b0,a1);
        }
        return reVal;
    }
};
