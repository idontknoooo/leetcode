// My solution 223ms
class Solution {
public:
   int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        return 4*count-repeat*2;
    }
};

// 142ms
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rtn = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            bool last = false;
            for (int j = 0; j < grid[0].size(); j++) {
                bool up = false;
                if (i-1 >= 0 && grid[i-1][j] == 1) {
                    up = true;
                }
                if (grid[i][j] == 0) {
                    last = false;
                } else {
                    if (last && up) {
                    } else if (last || up) {
                        rtn += 2;
                    } else {
                        rtn += 4;
                    }
                    last = true;
                }
            }
        }
        return rtn;
    }
};
