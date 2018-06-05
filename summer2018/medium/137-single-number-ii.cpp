// O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r0 = 0;
        int r1 = 0;

        for (auto e : nums)
        {
            r0 ^= e & ~r1;
            r1 ^= e & ~r0;
        }
        
        return r0;
    }
};

// bitwise
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            int count = 0;
            int mask = 1 << i;
            
            for(int j = 0; j < length; j++)
            {
                if(nums[j] & mask)
                    count++;
            }
            
            if(count % 3)
                res = res | mask;
        }
        
        return res;
    }
};


// 11ms


class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     int res = 0;
    //     for(int i = 0; i < 32; ++i) {
    //         int sum = 0;
    //         for(int j = 0; j < nums.size(); ++j) {
    //             sum += (nums[j] >> i) & 1;
    //         }
    //         res |= (sum % 3) << i;
    //     }
    //     return res;
    // }
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); ++i) {
            b = b ^ nums[i] & ~a;
            a = a ^ nums[i] & ~b;
        }
        return b;
    }
};


