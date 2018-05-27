class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j){
        vector<int> vec;
        unordered_map<int, int> um;
        for(int x = i; x < i+3; ++x){
            for(int y = j; y < j+3; ++y){
                if(grid[x][y] < 1 || grid[x][y] > 9) return false;
                um[grid[x][y]]++;
            }
        }
        for(auto p : um){
            if(p.second > 1) return false;
        }
        for(int x = i; x < i+3; ++x){
            int tmp = 0;
            for(int y = j; y < j+3; ++y){
                tmp += grid[x][y];
            }
            vec.push_back(tmp);
        }
        for(int x = j; x < j+3; ++x){
            int tmp = 0;
            for(int y = i; y < i+3; ++y){
                tmp += grid[y][x];
            }
            vec.push_back(tmp);
        }
        vec.push_back(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]);
        vec.push_back(grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]);
        for(int n = 0; n < vec.size()-1; ++n){
            if(vec[n] != vec[n+1]) return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3) return 0;
        int count = 0;
        for(int i = 0; i < grid.size()-2; ++i){
            for(int j = 0; j < grid[i].size()-2; ++j){
                if(isMagic(grid, i, j)){
                    count += 1;
                }
            }
        }
        return count;
    }
};
