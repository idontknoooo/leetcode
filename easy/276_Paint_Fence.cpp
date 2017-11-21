class Solution {
public:
 // int numWays(int n, int k) {
 //        if(n<=1 || k==0)return n*k;
 //        int a=k,b=k*(k-1),c=0,d=0;
 //        for(int i=2;i<n;++i){
 //            d=(k-1)*(a+b);
 //            a=b;b=d;
 //        }
 //        return a+b;
 //    }
    int numWays(int n, int k) {
        if (n == 0) return 0;
        vector<vector<int>> dp(2, vector<int>(n, -1));
        return numWaysRecursion(n, k, 0, false, dp);
    }
    
    int numWaysRecursion(int n, int k, int idx, bool if2, vector<vector<int>> &dp) {
        if (idx == n) return 1;
        if (dp[if2][idx] != -1) return dp[if2][idx];

        if (idx == 0) return dp[if2][idx] = k * numWaysRecursion(n, k, idx + 1, false, dp);

        if (if2 == false) return dp[if2][idx] = (k - 1) * numWaysRecursion(n, k, idx + 1, false, dp) + numWaysRecursion(n, k, idx + 1, true, dp);
        else return dp[if2][idx] = (k - 1) * numWaysRecursion(n, k, idx + 1, false, dp);
    }
};