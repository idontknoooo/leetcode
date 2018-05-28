// My solution 49ms, bead 44%
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> vec(nums.size(), 0);
        vector<int> ans;
        for(int num : nums){
            vec[num-1]++;
            if(vec[num-1]>1) ans.push_back(num);
        }
        for(int i = 0; i < vec.size(); ++i){
            if(!vec[i]) {
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};


// 39 ms solution
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        int missingNo = 0;
        int dupNo = 0;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }else{
                dupNo = abs(nums[i]);
            }
        }
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] > 0){
                missingNo = i+1;
                break;
            }
        }
        result.push_back(dupNo);
        result.push_back(missingNo);
        return result;
    }
};
