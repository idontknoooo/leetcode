// 4ms
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int start=0,end=nums.size()-1;
        int target=nums.back();
        while(start+1<end){
            int mid=(start+end)/2;
            if(nums[mid]<=target) end=mid;
            else start=mid;
        }
        if(nums[start]<=target) return nums[start];
        else return nums[end];
    }
};

// 5ms
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        
        while (start<end) {
            if (nums[start]<nums[end]) // not rotated.
                return nums[start];
            
            int mid = (start+end)/2;
            
            if (nums[mid]>=nums[start]) {// mid falls in ascending.
                start = mid+1;
            } else {
                end = mid; // min on left.
            }
        }
        
        return nums[start];
    }
};
