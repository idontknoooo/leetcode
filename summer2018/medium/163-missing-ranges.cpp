// 2ms
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        if (nums.size() == 0) return ans = vector<string>{range(lower, upper)};
        if (nums[0] > lower) ans.push_back(range(lower, nums[0] - 1));
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] != nums[i] && nums[i + 1] > nums[i] + 1) ans.push_back(range(nums[i] + 1, nums[i + 1] - 1));
        }
        if (nums[nums.size() - 1] < upper) ans.push_back(range(nums[nums.size() - 1] + 1, upper));
        return ans;
    }
    
private: 
    inline string range(int a, int b) {
        return a == b ? to_string(a) : (to_string(a) + "->" + to_string(b));
    }
};

// 2ms
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (nums.empty()) {
            if (lower == upper) result.push_back(to_string(lower));
            else result.push_back(to_string(lower) + "->" + to_string(upper));
        } 
        else {
            long next = lower;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < next) continue;
                else if (nums[i] == next){
                    next++;
                    continue;
                }
                else {
                    result.push_back(get(next, (long)nums[i] - 1));
                    next = (long)nums[i] + 1;
                }
            }
            if (next <= upper) result.push_back(get(next, (long)upper));
        }
        
        return result;
    }
    
    string get(int a, long b) {
        if (a == b) return to_string(a);
        else return to_string(a) + "->" + to_string(b);
    }
};
