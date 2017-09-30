// My solution, straight forward but no trick
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i+=2)
        {
            if(nums[i]!=nums[i+1])
            {
                return nums[i];
            }
        }
    }
};
// General Trick
// A XOR A == 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int tmp = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            tmp ^= nums[i];
        }
        return tmp; 
    }
};

return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
