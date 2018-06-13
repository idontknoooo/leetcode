// 14ms
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

// no sort, faster 12ms
class Solution {
public:
    string rankString(int rank) {
        if (rank == 1) return "Gold Medal";
        if (rank == 2) return "Silver Medal";
        if (rank == 3) return "Bronze Medal";
        return to_string(rank);
    }
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.size() == 0) return vector<string>();
        
        // Get max number for array size
        int m = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > m) m = nums[i];
        }
        
        vector<int> index(m + 1, -1);
        // Number to index, make an index array corresponding to number array
        for (int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i;
        }
        
        vector<string> rank(nums.size());
        int current_rank = 1;
        // Assign increamented rank on index array
        for (int j = index.size() - 1; j >= 0; --j) {
            if (index[j] >= 0) {
                rank[index[j]] = rankString(current_rank);
                current_rank++;
            }
        }
        
        return rank;
    }
};
