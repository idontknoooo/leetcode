// Unordered_map my solution 38ms
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        unordered_map<int, int> um1, um2;
        for(int n : nums){
            if(um1[n+k]){ um2[n]=n+k;}
            if(um1[n-k]){ um2[n-k]=n;}
            um1[n] = 1;
        }
        return um2.size();
    }
};


// My new solution use Sort(), 28ms
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() < 2 || k < 0) return 0;
        
        sort(nums.begin(), nums.end()); // Sort
        int count = 0;
        for(int i = 1, j = 0; i < nums.size() && j < nums.size();){
            if(nums[j] + k == nums[i]){ // If same
                while(nums[j+1] == nums[j]) ++j;
                ++count, ++j;
            } else if(nums[j] + k < nums[i]) { // If the smallest quick pointer is greater, then check next number by move slow pointer forward
                ++j;
            } else {
                // If smallest quick pointer is less, then increment quick pointer
                while(nums[j] + k > nums[i] && i < nums.size()) ++i;
                // If same
                if(nums[j] + k == nums[i]) ++count;
                // Check if next one is same as current, if true, move forward
                while(nums[j+1] == nums[j]) ++j;
                ++j;
            }
            i = j+1;
        }
        return count;
    }
};
