// 17 ms
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
}; 


// 16ms
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int k = -1;
      // Find rotate points
      // 3 2 1 -> return -1
      // 1 2 3 -> return 1, which has value 2
      // 2 3 1 -> return 0, which has value 2
      for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
          k = i; // if found, breaks
          break;
        }
      } 
      // If no smallest, reverse 
      if (k == -1) {
          reverse(nums.begin(), nums.end());
          return;
      }
      int l = -1;
      // find first value that greater than nums[k]
      for (int i = nums.size() - 1; i > k; i--) {
        if (nums[i] > nums[k]) {
          l = i;
          break;
        } 
      } 
      swap(nums[k], nums[l]); // swap small & large and reverse
      reverse(nums.begin() + k + 1, nums.end());  // reverse from small to end
    }
}; 

