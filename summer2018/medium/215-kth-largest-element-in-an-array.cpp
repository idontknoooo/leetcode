// 10ms 98%
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKIndex(nums, 0, nums.size()-1, nums.size()-k);
    }
    
    int findKIndex(vector<int> &nums, int left, int right, int index){
        int target = nums[index];
  // trick: reduce unnecessary raverse
        swap(nums[index], nums[left]);
        int l = left, r = right;
        
        while(l < r) {
            for (;target < nums[r] && r > l;r--);
            if (r > l) nums[l] = nums[r];
            else break;
            l++;
            
            for (;target > nums[l] && l < r;l++);
            if (l < r) nums[r] = nums[l];
            else break;
            r--;
        }
        nums[l] = target;
        
        if (l == index) return target;
        else if (l < index) return findKIndex(nums, l+1, right, index);
        else return findKIndex(nums, left, l-1, index);
    }
};
