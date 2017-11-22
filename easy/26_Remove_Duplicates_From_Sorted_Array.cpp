class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
			// Count repeat
            if(nums[i] == nums[i-1]) count++;
			// Overwrite repeat
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;
    }
};

// Use unique method and erase for vector
// Final vector will have all unique member and bunch of empty space at the end
int removeDuplicates(vector<int>& nums) {
    auto it = std::unique(nums.begin(), nums.end());
    nums.erase(it, nums.end());
    return nums.size();
}


// 100% Submission with cheat code, 16 ms
static int x=[](){
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();
int removeDuplicates(vector<int>& nums){
    int a = 1;
    for(int i = 1; i < nums.size(); ++i){
        if(nums[i]!=nums[i-1]){
            nums[a++] = nums[i];
        }
    }
    return a>nums.size()? nums.size() : a;
}