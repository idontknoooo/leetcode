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
// A XOR 0 == A
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

// Super clean solution
return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

// Hashmap solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> us;
        for(int num : nums){
            if(us.find(num)==us.end())
                us.insert(num);
            else
                us.erase(num);
        }
        return *us.begin();
    }
};

// Mathematics Solution
// 2*unique_sum - un_unique_vector = single value
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> us;
        for(int num : nums){
            if(us.find(num)==us.end())
                us.insert(num);
        }
        int tmp = 0;
        for(int num : us){
            tmp += num;
        }
        tmp *= 2;
        for(int num : nums){
            tmp -= num;
        }
        return tmp;
    }
};