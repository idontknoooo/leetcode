// 14ms

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size();
        if(row == 0) return count;
        int col = grid[0].size();
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j]=='1')
                {
                    search(i, j, grid,row, col);
                    count++;
                }
        return count;
    }
    void search(int i, int j, vector<vector<char>>& grid, int row, int col)
    {
        if(i<0 || i>=row|| j<0 || j>=col || grid[i][j]!='1') return;
        grid[i][j] = '0'; 
        search(i+1, j, grid, row, col);
        search(i-1, j, grid, row, col);
        search(i, j-1, grid, row, col);
        search(i, j+1, grid, row, col);
    }
};


