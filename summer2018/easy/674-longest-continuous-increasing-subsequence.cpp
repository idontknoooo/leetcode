// 15ms my solution beat 66%
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int len = 1, cur = 1;
        for(int i = 0; i < nums.size()-1; ++i) {
            if(nums[i] < nums[i+1]) {
                ++cur;
            } else {
                len = max(len, cur);
                cur = 1;
            }
        }
        len = max(len, cur);
        return len;
    }
};


