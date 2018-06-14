// My solution | align with unique path 1 | 4ms beat 99%
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& OG) {
        int M = OG.size();
        int N = OG[0].size();
        
        if(OG[0][0]==1) return 0;
        vector<int> dp(N, 0);
        dp[0] = 1;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(dp[j]!=0 && j==0) dp[j] = 1;
                if(j>0) dp[j] += dp[j-1];
                if(OG[i][j]==1) dp[j] = 0;
            }
        }
        return dp[N-1];
    }
};
// 99% 2ms
class Solution { 
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // space: O(m*n)
//         int m = obstacleGrid.size();
//         if(m == 0) return 0;
//         int n = obstacleGrid[0].size();
        
//         vector<vector<int>> dp = obstacleGrid;
//         int temp = 1;
//         for(int i = 0; i < m; ++i){
//             if(dp[i][0] == 1){
//                 temp = 0;
//             }
//             dp[i][0] = temp;
//         }
//         temp = dp[0][0];
//         for(int i = 1; i < n; ++i){
//             if(dp[0][i] == 1){
//                 temp = 0;
//             }
//             dp[0][i] = temp;
//         }
        
//         for(int i = 1; i < m; ++i){
//             for(int j = 1; j < n; ++j){
//                 if(dp[i][j] == 1){
//                     dp[i][j] = 0;
//                     continue;
//                 }
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }
//         return dp[m-1][n-1];
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> dp(n, 0);
        if(obstacleGrid[0][0] == 0) dp[0] = 1;
        for(int i = 1; i < n; ++i){ // for each colum, if meet obstacle, assign dp to 0
            if(obstacleGrid[0][i] == 1){
                dp[i] = 0;
                continue;
            }
            dp[i] = obstacleGrid[0][i-1] == 1 ? 0 : dp[i-1];
        }
        
        for(int i = 1; i < m; ++i){
            if(obstacleGrid[i][0] == 1) dp[0] = 0;
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    continue;
                }
                // Check if previous row is obstacle
                // if yes, assign 0, otherwise, keep same
                dp[j] = obstacleGrid[i-1][j] == 1 ? 0 : dp[j];
                // Check if previous col is obstacle
                // if yes, assign 0, else add to previous
                dp[j] += obstacleGrid[i][j - 1] == 1 ? 0 : dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};
