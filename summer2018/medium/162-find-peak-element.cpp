// 6ms
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return false;
        int begin=0; 
        int end=nums.size()-1;
        while(begin<end){
            int mid=(begin+end)/2;
            if(nums[mid]<nums[mid+1]) begin=mid+1;
            else end=mid;
        }
        return begin;
    }
};
