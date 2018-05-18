class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); ++i)
        {
            if (0 == nums[i])
                continue;
            
            nums[j] = nums[i];
            ++j;
        }
        
        for (; j < nums.size(); ++j)
            nums[j] = 0;
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = nums.size()-1; i >= 0; --i){
            int tmp = i;
            while(!nums[tmp] && tmp!=nums.size()-1){
                int val = nums[tmp];
                nums[tmp] = nums[tmp+1];
                nums[tmp+1] = val;
                ++tmp;
            }
        }
    }
};
