// 15ms beat 98%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size()<4) return res;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-3; i++) { // first number
            if(i>0 && nums[i]==nums[i-1]) continue; // eliminate repeats
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break; // optimization, avoid overlap
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue; // optimization, increment i
            for (int j = i+1; j < n-2; j++) { // second number
                if(j>i+1 && nums[j]==nums[j-1]) continue; // eliminate repeats
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break; // avoid overlap
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1] < target) continue; // optimization
                int left = j+1;
                int right = n-1;
                while (left<right) { // 3rd and 4th numbers
                    if(nums[i]+nums[j]+nums[left]+nums[right] > target) --right;
                    else if (nums[i]+nums[j]+nums[left]+nums[right] < target) ++left;
                    else {
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return res;
    }
};
