class Solution {
public:
//     int missingNumber(vector<int>& nums) {
//         int result = nums.size();
//         int i=0;
        
//         for(int num:nums){
//             result ^= num;
//             result ^= i;
//             i++;
//         }
        
//         return result;
//     }
//     int missingNumber(vector<int>& nums) {
//     long n = nums.size();
//     return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
// }
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ i ^ nums[i];
        }
        return ans;
    }
};