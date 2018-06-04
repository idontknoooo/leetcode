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
