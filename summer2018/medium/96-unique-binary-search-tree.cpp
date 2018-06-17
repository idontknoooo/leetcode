// 2ms 主要还是举例子 找规律
/*
n   = 1  2  3  4
res = 1  2  5  14

n = 1
1

n = 2
1-2 or 2-1

n = 3
1-(2-3) 1-(3-2) | 1-2-3 | (1-2)-3 (2-1)-3
dp[0]*dp[3-1-0] + dp[1][3-1-1] + dp[2][3-1-2]

SUM(dp[j]*dp[n-1-j]);
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n+1, 0);
        ans[0] = ans[1] = 1;
        for(int i = 2; i <= n; ++i) {
            int tmp = 0;
            for(int j = 0; j < i; ++j) 
                tmp += ans[j] * ans[i-1-j];
            ans[i] = tmp;
        } 
        return ans[n];
    }
};
class Solution {  
public:  
    int numTrees(int n) {  
        int *G = new int[n + 1]();  
        G[0] = 1;  
        G[1] = 1;  
        for(int i = 2; i <= n; i++){  
            for(int j = 0; j < i; j++)  
                G[i] += G[j]*G[i - j - 1];  
        }  
        return G[n];  
    }  
};  
