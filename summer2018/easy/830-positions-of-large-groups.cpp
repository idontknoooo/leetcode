// My solution 13ms
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > mat;
        int  count = 1, i = 0;
        char cur = S[0];
        for(i = 0; i < S.length() - 1; ++i) {
            if(cur == S[i+1]) {
                count++;
            } else {
                if(count >= 3) mat.push_back(vector<int> {i-count+1, i});
                count = 1;
                cur = S[i+1];
            }
        }
        if(count >= 3) mat.push_back(vector<int> {i-count+1, i});
        
        return mat;
    }
};
