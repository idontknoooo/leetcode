class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums.size()/2;
        vector<int> tmp;
        int i = 0;
        while(i < nums.size())
        {
            if(find(tmp.begin(), tmp.end(), nums[i])==tmp.end())
            {
                if(count(nums.begin(), nums.end(), nums[i])>maj)
                    return nums[i];
                else
                    tmp.push_back(nums[i]);
            }
            ++i;
        }
        cout << i << endl;
        return nums[i];
    }
};