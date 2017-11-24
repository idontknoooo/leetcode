class Solution {
public:
    // Binary Search O(logN)
    int searchInsert(vector<int>& nums, int target) {

        int start = 0, end = nums.size()-1;
        while(start <= end){
            // int mid = (start+end)/2;
            int mid = start + (end-start)/2;
            if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return start;
    }
};
