class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        vector<pair<int,int>> relativeranks;

        for(int i =0;i<nums.size();i++)
            relativeranks.push_back({nums[i],i});

        sort(relativeranks.begin(),relativeranks.end(),[](pair<int,int>a,pair<int,int>b){return a.first>b.first;});        

        for(int i = 0;i<relativeranks.size();i++)
        {
            if(i==0) res[relativeranks[i].second] = "Gold Medal";
            else if(i==1) res[relativeranks[i].second] = "Silver Medal";
            else if(i==2) res[relativeranks[i].second] = "Bronze Medal";
            else res[relativeranks[i].second]=to_string(i+1);
        }
        return res;  
    }
};

