class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int min_num = INT_MAX, max_num = INT_MIN;
        int true_sum = 0, cur_sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            cur_sum += nums[i];
            max_num = max_num>nums[i]? max_num : nums[i];
            min_num = min_num<nums[i]? min_num : nums[i];
        }
        max_num = nums.size()>max_num? nums.size() : max_num;
        true_sum = (1 + max_num) * max_num / 2;
        return true_sum - cur_sum;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        return (n + 1) * n / 2 - sum;
    }
};
