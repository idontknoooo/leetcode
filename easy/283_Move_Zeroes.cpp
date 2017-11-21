class Solution {
public:
//     void moveZeroes(vector<int>& nums) {
//         int last = 0, cur = 0;
    
//     while(cur < nums.size()) {
//         if(nums[cur] != 0) {
//             swap(nums[last], nums[cur]);
//             last++;
//         }
        
//         cur++;
//     }
//     }
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 0;
        while(end < nums.size()) {
            if (nums[end] != 0) {
                nums[start] = nums[end];
                start++;
                
            } 
            end++;
        }
        for (int i = start; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};