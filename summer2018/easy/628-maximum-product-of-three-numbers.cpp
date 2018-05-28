// My solution 75ms beat 24%
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0] * nums[1] * nums[nums.size()-1] > nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3]? nums[0] * nums[1] * nums[nums.size()-1] : nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
    }
};


// 47ms: Track 2 minimum and 3 maximum
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        
        for(const auto n : nums) {
            if(n >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if(n >= max2) {
                max3 = max2;
                max2 = n;
            }
            else if(n > max3) {
                max3 = n;
            }
            
            if(n <= min1) {
                min2 = min1;
                min1 = n;
            }
            else if(n < min2) {
                min2 = n;
            }
        }
        
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
