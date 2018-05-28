// My solution 202 ms
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int> > mat = M;
        for(int i = 0; i < M.size(); ++i){
            for(int j = 0; j < M[i].size(); ++j){
                int sum = 0, count = 0;
                for(int a = i-1; a < i+2; ++a){
                    for(int b = j-1; b < j+2; ++b){
                        if(a >= 0 && b >= 0 && a < M.size() && b < M[i].size()){
                            sum += M[a][b];
                            count++;
                        }
                    }
                }
                mat[i][j] = sum / count;
            }
        }
        return mat;
    }
};


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        if (m == 0) return {{}};
        int n = M[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = M[i][j];
                int cnt = 1;
                if (i > 0) {
                    sum += M[i-1][j]; ++cnt;
                    
                    if (j > 0) {
                        sum += M[i-1][j-1]; ++cnt;
                    }
                    if (j < n-1) {
                        sum += M[i-1][j+1]; ++cnt;
                    }
                }
                if (i < m-1) {
                    sum += M[i+1][j]; ++cnt;
                    
                    if (j > 0) {
                        sum += M[i+1][j-1]; ++cnt;
                    }
                    if (j < n-1) {
                        sum += M[i+1][j+1]; ++cnt;
                    }
                }
                if (j > 0) {
                    sum += M[i][j-1]; ++cnt;
                }
                if (j < n-1) {
                    sum += M[i][j+1]; ++cnt;
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};
