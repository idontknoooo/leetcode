// My solution 4ms beat 100%
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) m[nums[i]]++;
        
        for(int i = 0, j = 0; i < 3; ++i)
            while(m[i]--) nums[j++] = i;
    }
};


// 4ms better solution one pass O(1) space 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int zero_index = 0;     // All number before it will be zero
        int two_index  = len-1; // All number after it will be 2
        for(int i=0; i <= two_index; i++){
            if(!nums[i])
                swap(nums[i], nums[zero_index++]);
            else if(nums[i]==2)
                swap(nums[i--], nums[two_index--]);
        }
        return;
    }
};
