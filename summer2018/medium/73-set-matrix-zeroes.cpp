// my solution 55ms beat 88%
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, col;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                if(!matrix[i][j]) row.insert(i), col.insert(j);
            }
        }
        for(int i : row) {
            matrix[i] = vector<int> (matrix[i].size(), 0);
        }
        //for(int i : row) {
        //    for(int j = 0; j < matrix[i].size(); ++j) {
        //        matrix[i][j] = 0;
        //    }
        //}
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j : col)
                matrix[i][j] = 0;
        }
    }
};


// 53ms
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m > 0){
            int n = matrix[0].size();
            set<int> row_set;
            set<int> col_set;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(matrix[i][j] == 0){
                        row_set.insert(i);
                        col_set.insert(j);
                    }
                }
            }
            for(auto it = row_set.begin(); it != row_set.end(); ++it){
                for(int j = 0; j < n; ++j){
                    matrix[*it][j] = 0;
                }
            }
            
            for(auto it = col_set.begin(); it != col_set.end(); ++it){
                for(int i = 0; i < m; ++i){
                    matrix[i][*it] = 0;
                }
            }
        }
    }
};


// O(1) space solution
//  Adaptation from: https://leetcode.com/problems/set-matrix-zeroes/discuss/133136/C++-O(1)-two-steps-with-explanation
//  
//  This solution uses first col and row as temp arrays to store statistic.
//  Step 1: check if there are zeros in first col and row
//  Step 2: check the remaining matrix one by one and put zeros into the first col and row for storing statistic
//  Step 3: use the temp arrays to set zeros for the matrix
//  Step 4. set zeros for the first col and row

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size()==0) return;
        int m = matrix.size(), n = matrix[0].size();
        int col = 1, row = 1; // 0: there is zero; 1: there is no zero
        //check if there exists any zero so we can use the col row as temp array
        for(int i = 0; i < m; i++)
            if(matrix[i][0]==0) col = 0;
        //check if there exists any zero so we can use the first row as temp array
        for(int j = 0; j < n; j++)
            if(matrix[0][j]==0) row = 0;
        //scan all the elements and put stat into the temp row and col
        for(int i = 1; i<m;i++)
            for(int j = 1; j<n;j++)
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        //use the temp row and col to set zeros
        for(int i = 1; i<m;i++)
            for(int j = 1; j<n;j++)
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
        //now set zero for the first row and column
        if(col == 0) for(int i = 0; i < m; i++) matrix[i][0] = 0;
        if(row == 0) for(int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};
