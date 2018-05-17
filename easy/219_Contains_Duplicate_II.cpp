class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//          unordered_set<int> s;
       
//        if (k <= 0) return false;
//        if (k >= nums.size()) k = nums.size() - 1;
       
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (i > k) s.erase(nums[i - k - 1]);
//            if (s.find(nums[i]) != s.end()) return true;
//            s.insert(nums[i]);
//        }
       
//        return false;
        if(k==0) return false;
        if(nums.size()==0) return false;
        int max = nums[0], min = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>max) max = nums[i];
            if(nums[i]<min) min = nums[i];
        }
        int* p = new int[max-min+1];
        for(int i = 0;i<max-min+1;i++) p[i] = -1;
        for(int i = 0;i<nums.size();i++){
            if(p[nums[i]-min]!=-1){
                if(i-p[nums[i]-min]<=k) return true;
                else p[nums[i]-min] = i;
            }
            else p[nums[i]-min] = i;
        }
        return false;
    }
};
