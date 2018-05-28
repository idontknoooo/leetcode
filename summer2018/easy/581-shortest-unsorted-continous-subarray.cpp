// My solution 56ms beat 24%
// Sort and check different position
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int i = 0, j = nums.size()-1;
        bool tf1 = true, tf2 = true;
        while(i < j && (tf1 || tf2)){
            if(tf1 && vec[i]!=nums[i]){
                tf1 = false;
            } else if (tf1) {
                ++i;
            }
            if(tf2 && vec[j]!=nums[j]){
                tf2 = false;
            } else if (tf2) {
                --j;
            }
        }
        return i==j? 0 : j - i + 1;
    }
};


// 38ms 90%
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size=nums.size();
        int end=-2, beg=-1;
        if(nums.empty()) return 0;
        int maxx=nums[0], minn=nums[size-1];
        for(int i=1; i<size; i++)
        {
            maxx=max(maxx,nums[i]);
            if(nums[i]<maxx)
                end=i;
            minn=min(minn,nums[size-1-i]);
            if(nums[size-1-i]>minn)
                beg=size-1-i;    
        }
        int len=end-beg+1;
        return len;
    }
};
