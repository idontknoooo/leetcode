// my solution very slow
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum = INT_MIN;
        for(int i = 0; i < nums.size()-k+1; i++) {
            int j = i, tmp = 0;;
            while(j < i+k) tmp += nums[j++];
            max_sum = max_sum > tmp? max_sum : tmp;
        }
        return max_sum*1.0/k;
    }
};


// 173ms
// Add new, remove oldest
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int maxSum = sum;
        
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum/(double)k;
    }
};
