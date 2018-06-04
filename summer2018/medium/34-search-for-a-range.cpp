// 13ms
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) >> 1;
            if (nums[start] != target || nums[end] != target) {
                if (nums[start] != target && nums[end] != target) {
                    if (nums[mid] > target) end = mid - 1;
                    else if (nums[mid] < target) start = mid + 1;
                    else { ++start; --end; }
                }
                else if (nums[start] != target) {
                    if (nums[mid] == target) ++start;
                    else start = mid + 1;
                }
                else {
                    if (nums[mid] == target) --end;
                    else end = mid - 1;
                }
            }
            else return vector<int>{start, end};
        }
        return vector<int>{-1, -1};
    }
};

// 10ms
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        
        if(nums.empty())
            return res;
        
        int pos = -1;
        if(nums[0] == target)
            pos = 0;
        else if(nums[nums.size()-1] == target)
            pos = nums.size() - 1;
        else
            pos = findTarget(nums, 0, nums.size()-1, target);
            
        if(pos < 0)
            return res;
        
        res[0] = findLowerBound(nums, 0, pos);
        if(nums[res[0]] < target)
            res[0]++;
        res[1] = findUpperBound(nums, pos, nums.size()-1);
        if(nums[res[1]] > target)
            res[1]--;
        return res;
    }
    
    int findTarget(vector<int>& nums, int min, int max, int target)
    {
        if(min >= max)
            return -1;
        
        if(nums[min] > target || nums[max] < target)
            return -1;
        
        if(min + 1 == max)
            return -1;
        
        int med = (min + max)/2;
        
        if(nums[med] == target)
            return med;
        else if(nums[med] > target)
            return findTarget(nums, min, med, target);
        else
            return findTarget(nums, med, max, target);
    }
    
    int findLowerBound(vector<int>& nums, int min, int max)
    {
        if(min == max)
            return min;
        
        int med = (min + max)/2;
        
        if(nums[med+1] == nums[max] && nums[med] < nums[max])
            return med;
        else if(nums[med] == nums[max])
            return findLowerBound(nums, min, med);
        else
            return findLowerBound(nums, med, max);
    }
    
    int findUpperBound(vector<int>& nums, int min, int max)
    {
        if(min == max)
            return min;
        
        int med = (min + max + 1)/2;
        
        if(nums[med-1] == nums[min] && nums[med] > nums[min])
            return med;
        else if(nums[med] == nums[min])
            return findUpperBound(nums, med, max);
        else
            return findUpperBound(nums, min, med);
    }
};
