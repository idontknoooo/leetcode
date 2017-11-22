class Solution {
public:
    // Double pointer
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size()) return 0;
        int a = 0; // first pointer, i is second pointer
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]!=val){
                nums[a++] = nums[i];
            }
        }
        return a;
    }
};
