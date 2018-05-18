class Solution {
public:
    int numWays(int n, int k) {
        if(!n) return 0;
        int rep = 0, total = k;
        for(int i = 1; i < n; ++i){
            int tmp = total;
            total = (total-rep)*(k) + rep*(k-1);
            rep   = tmp - rep;
        }
        return total;
    }
};
