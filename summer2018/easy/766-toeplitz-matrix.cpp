class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return true;
        
        for (int j = matrix[0].size(), i = 0; j >= 0; j--) {
            int p = i;
            int q = j;
            int n = matrix[i][j];
            while (p >= 0 && q >= 0 && p < matrix.size() && q < matrix[0].size()) {
                if (matrix[p][q] != n)
                    return false;
                p++;
                q++;
            }
        }
        for (int i = 1, j = 0; i < matrix.size(); i++) {
            int p = i;
            int q = j;
            int n = matrix[i][j];
            while (p >= 0 && q >= 0 && p < matrix.size() && q < matrix[0].size()) {
                if (matrix[p][q] != n)
                    return false;
                p++;
                q++;
            }
        }
        return true;
    }
};


// 
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(matrix[i][j] != matrix[i - 1][j - 1]) return false;
        return true;
    }
};
