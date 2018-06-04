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
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        
        bool last_col_zeros = false;
        for (int m = 0; m < M; m++) {
            if (!matrix[m][N-1]) last_col_zeros = true;
            bool row_zeros = false;
            for (int n = 0; n < N; n++)
                if (!matrix[m][n]) { row_zeros = true; break; }
            if (row_zeros) for (int x = 0; x < N; x++)
                matrix[m][x] = !(matrix[m][x] || x == N-1);
        }
        for (int n = 0; n < N-1; n++)
            for (int m = 0; m < M; m++)
                if (matrix[m][n] == 1 && !matrix[m][N-1])
                    for (int y = 0; y < M; y++) matrix[y][n] = 0;
                        
        if (last_col_zeros) for (int m = 0; m < M; m++)
            matrix[m][N-1] = 0;
    }
};
