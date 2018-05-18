class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int flag = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == INT_MIN)
                flag = 1;
            if (max < nums[i]) {
                max3 = max2;
                max2 = max;
                max = nums[i];
            } else if (max2 < nums[i] && max > nums[i]) {
                max3 = max2;
                max2 = nums[i];
            } else if (max3 < nums[i] && max2 > nums[i])
                max3 = nums[i];
        }
        
        if (max3 != INT_MIN || (max3 != max2 && flag == 1))
            return max3;
        else
            return max;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > a){
                c = b, b = a, a = nums[i];
            } else if(nums[i] > b && nums[i] != a) {
                c = b, b = nums[i];
            } else if(nums[i] > c && nums[i] != b && nums[i] != a) 
                c = nums[i];
        }
        return s.size()<3? a : c;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        auto it = s.rbegin();
        if(s.size()>=3) ++it, ++it;
        return *it;
    }
};
