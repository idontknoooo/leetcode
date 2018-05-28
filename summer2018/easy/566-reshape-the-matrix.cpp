// My solution 39ms beat 99.5%
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()==0) return nums;
        int col = nums[0].size() * nums.size();
        if(col%r) return nums;

        col /= r;
        vector<vector<int> > mat;
        vector<int> vec;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < nums[i].size(); ++j){
                vec.push_back(nums[i][j]);
                if(vec.size() == col){
                    mat.push_back(vec);
                    vec.clear();
                }
            }
        }
        return mat;
    }
};
