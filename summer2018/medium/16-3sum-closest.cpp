// beat 89% 10ms
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());
        
        int sum = INT_MAX;
        for(int i = 0; i < nums.size() - 2; i++) {
            
            int j = i+1, k = nums.size() - 1;

            while(j < k) {
                int curr_sum = nums[i] + nums[j] + nums[k];
                
                if(curr_sum == target) return curr_sum;
                else if(curr_sum < target) j++;
                else --k;
                
                if(sum == INT_MAX || abs(curr_sum - target) < abs(sum - target)) sum = curr_sum;
            }
        }
        return sum;
    }
};
