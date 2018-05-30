class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int i = 0, j = 0, jr = A[i].size()-1, tmp = 0;
        for(; i < A.size(); ++i) {
            j = 0, jr = A[i].size()-1;
            while(j <= jr) {
               if(j == jr) {
                   A[i][j] = !(A[i][j]^0);
               } else {
                   A[i][j] = !(A[i][j]^0);
                   A[i][jr] = !(A[i][jr]^0);
                   
                   tmp = A[i][j];
                   A[i][j] = A[i][jr];
                   A[i][jr] = tmp;
               }
               ++j, --jr; 
            }
        }
        return A;
    }
};
