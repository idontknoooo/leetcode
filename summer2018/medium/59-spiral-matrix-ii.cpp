// beat 100%
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int number=1;
        for(int i=0;i<(n+1)/2;i++){
            for(int j=i;j<n-i;j++)
                ret[i][j]=number++;
            for(int j=i+1;j<n-i;j++)
                ret[j][n-i-1]=number++;
            for(int j=n-i-2;j>=i;j--)
                ret[n-i-1][j]=number++;
            for(int j=n-i-2;j>i;j--)
                ret[j][i]=number++;
        }
        return ret;
    }
};

// My solution
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int> (n, 0));
        int row = n-1, col = n-1;
        int c = 1, low_row = 0, low_col = 0, cur_row = 0, cur_col = 0;
        while(low_row <= row && low_col <= col) {
            
            for(cur_col = low_col; cur_col <= col; ++cur_col, ++c) {
                ans[low_row][cur_col] = c;
            }
            low_row++;
            
            for(cur_row = low_row; cur_row <= row; ++cur_row, ++c) {
                ans[cur_row][col] = c;
            }
            col--;
            
            for(cur_col = col; cur_col >= low_col && low_row <= row; --cur_col, ++c) {
                ans[row][cur_col] = c;
            }
            row--;
            
            for(cur_row = row; cur_row >= low_row && low_col <= col; --cur_row, ++c) {
                ans[cur_row][low_col] = c;
            }
            low_col++;
        }   
        return ans;
    }
};
