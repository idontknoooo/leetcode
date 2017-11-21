class Solution {
public:
    // int minCost(vector<vector<int>>& costs) {
    //     int n = costs.size();
    //     for (int i = 1; i < n; i++) {
    //         costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
    //         costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
    //         costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
    //     }
    //     return (n == 0) ? 0 : (std::min(costs[n - 1][0], std::min(costs[n - 1][1], costs[n - 1][2])));
    // }
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        int n=costs.size();
        vector<vector<int> > dp=costs; //dp[i][j] the min cost paint from house i+1 to j;
        for(int i=1;i<dp.size();++i){
            for(int j=0;j<3;++j){
                dp[i][j]+=min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        return min(dp.back()[0], min(dp.back()[1], dp.back()[2]));
    }
};