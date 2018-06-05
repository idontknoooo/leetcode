// 14ms solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

// my 18ms solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        else if(nums.size() == 1) return 1;
        int slow = 0, cur_val = nums[0], fast = 1, counter = 1;
        for(;fast < nums.size(); ++fast) {
            if(cur_val == nums[fast] && counter >= 2) {
                ++counter;
            } else if(cur_val == nums[fast] && counter < 2) {
                counter = 2;
                nums[slow++] = cur_val;
            } else {
                counter = 1;
                nums[slow++] = cur_val;
                cur_val = nums[fast];
            }
        }
        if(counter == 2 && cur_val == nums[slow] || (cur_val != nums[slow])) {
            nums[slow++] = cur_val;
        } else ++slow;
        return slow;
    }
};
