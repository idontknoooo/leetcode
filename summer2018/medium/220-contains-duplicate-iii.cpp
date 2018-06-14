// 10ms beat 99%
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0) {
            return false;
        }
        if (k >= nums.size()) {
            k = nums.size() - 1;
        }
        // using long as test cases test large numbers
        unordered_set<long> storage;
        for (size_t i = 0; i < nums.size(); i++) {
        // keep a sliding window of k unique numbers
            if (i > k) {
                storage.erase(nums[i - k - 1]);
            }
        // optimized part: if t is small, try to find nums[i] - t, nums[i] - t + 1, ..., nums[i] + t respectively
       // if k is small, go through the entire set (since the number of elements in the set is small)
            if (t < k) {
                for (int j = nums[i] - t; j <= nums[i] + t; j++) {
                    if (storage.count(j)) {
                        return true;
                    }
                }
            } else {
                for (auto it = storage.begin(); it != storage.end(); ++it) {
                    if (abs(*it - nums[i]) <= t) {
                        return true;
                    }
                }
            }
            storage.insert(nums[i]);
        }
        return false;        
    }
};
