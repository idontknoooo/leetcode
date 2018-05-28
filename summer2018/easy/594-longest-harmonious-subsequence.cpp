// My solution 115ms beat 35%
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> um;
        for(int n : nums)
            um[n]++;
        int max_len = 0, tmp = 0, pre = 0, pre_val = 0;
        for(auto p : um){
            tmp     = p.second + pre_val;
            if(tmp != p.second && p.first == pre + 1)
                max_len = max(max_len, tmp);
            pre     = p.first;
            pre_val = p.second;
        }
        return max_len;
    }
};
