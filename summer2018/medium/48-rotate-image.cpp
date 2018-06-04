// Rotate will missing data since it's assymetrical, but swap is symetrical, thus use swap to replace it
// 4ms solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0, end = matrix.size()-1;
        while(start<end){
            for(int i=start; i<end; i++){
                int offset = i-start;
                int tmp = matrix[start][i];
                // Swap based on diagnal
                matrix[start][i] = matrix[end-offset][start];
                matrix[end-offset][start] = matrix[end][end-offset];
                // Swap based on vertical middle line
                matrix[end][end-offset] = matrix[start+offset][end];
                matrix[start+offset][end] = tmp;
            }
            start++; end--;
        }
    }
};


// 7ms
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
            for(int j=i;j<matrix.size();j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int i=0;i<matrix.size();i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};
