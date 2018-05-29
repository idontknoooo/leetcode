// My solution 54ms, add 1 element to left, minus 1 element from right
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(!nums.size()) return -1;
        if(nums.size()==1) return 0;
        
        int left = 0;
        int right = accumulate(nums.begin()+1, nums.end(), 0);
        int i = 0;
        for(; i < nums.size()-1; ++i){
            if(left == right) return i;
            left += nums[i];
            right -= nums[i+1];
        }
        return left==right? i : -1;
    }
};


// 34ms
class Solution {
public:
 int pivotIndex(vector<int>& nums) {
    if(nums.size()==0)return -1;
    int sum=0,total=0;
    
    // for loop faster than accumulate
    for (int i=0; i<nums.size(); ++i)
        total+=nums[i];
    
    for (int i=0; i<nums.size(); ++i){
        // left == right
        if(sum==total-nums[i]-sum)
            return i;
        sum+=nums[i];
    }
    return -1;
}
};
