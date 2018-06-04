// 10ms
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m==0) return 0;
        int n = grid[0].size();
        if (n==0) return 0;
        
        // Initialization
        //i=0;
        for (int j=1;j<n;j++)
            grid[0][j] += grid[0][j-1]; // make sum to right
        //j=0;
        for (int i=1;i<m;i++)
            grid[i][0] += grid[i-1][0]; // make sum downwards
        
        for (int i=1;i<m;i++)
            for (int j=1;j<n;j++)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        
        return grid[m-1][n-1];
        
    }
};
