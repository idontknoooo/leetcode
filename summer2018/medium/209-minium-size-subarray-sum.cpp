// 15ms
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int p = 0, q = 0, sum = nums[0];
        int ans = nums.size() + 1;
        while (p < nums.size() && q < nums.size()) {
            if (sum < s) {
                p++;
                sum += nums[p];
            } else {
                ans = min(ans, p - q + 1);
                sum -= nums[q];
                q++;
            }
        }
        return ans == nums.size() + 1 ? 0 : ans;
    }
};
// 10ms
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {  
        //TL O(n^2)
        // int min = nums.size();
        // for(int i = 0;i < nums.size();i++){
        //     int sum = 0;
        //     for(int j = i;j < nums.size() && sum < s;j++){
        //         sum += nums[j];
        //         if(sum >= s)
        //         {
        //             if(min > j-i+1)
        //                 min = j-i+1;
        //         }
        //     }
        //     if(i = 0 && sum < s)
        //         return 0;
        // }
        // return min;
        
        //
        int size = nums.size();
        if(size == 0)
            return 0;
        int left = 0,right = 0,sum = 0,res = size+1;
        while(right < size){
            while(right < size && sum < s)
                sum+=nums[right++];
            while(sum >= s){
                res = min(res,right-left);
                sum -= nums[left++];
            }
        }
        return res==size+1?0:res;     
    }
};
