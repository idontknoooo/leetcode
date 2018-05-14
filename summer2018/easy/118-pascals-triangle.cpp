class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > mat;
        if(numRows==0) return mat;
        mat.push_back({1});
        if(numRows==1) return mat;
        mat.push_back({1,1});
        if(numRows==2) return mat;
        for(int i = 2; i < numRows; ++i){
            vector<int> vec;
            for(int j = 0; j <= i; ++j){
                if(j == 0 || j == i)
                    vec.push_back(1);
                else
                    vec.push_back(mat[i-1][j]+mat[i-1][j-1]);
            }
            mat.push_back(vec);
        }
        return mat;
    }
};
