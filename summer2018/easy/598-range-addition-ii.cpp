// My solution 12 ms, beat 22%
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(!ops.size()) return m*n;
        int min_r = INT_MAX, min_c = INT_MAX;
        for(int i = 0; i < ops.size(); ++i){
            int tmp_r = ops[i][0], tmp_c = ops[i][1];
            if(ops[i][0] > m) tmp_r = m;
            if(ops[i][1] > n) tmp_c = n;
            if(min_r > tmp_r) min_r = tmp_r;
            if(min_c > tmp_c) min_c = tmp_c;
        }
        return min_r * min_c;
    }
};

// 9ms solution 
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r=m,c=n;
        for(vector<int> &op:ops)
        {
            r=min(r,op[0]);
            c=min(c,op[1]);
        }
        return r*c;
    }
};
