// 19ms beat 99%
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (0 == m) return 0;
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '0') continue;
                int tmp = min(dp[i][j - 1], dp[i - 1][j]);
                int cur = min(tmp, dp[i - 1][j - 1]);
                dp[i][j] = cur + 1;
                res = max(dp[i][j], res);
            }
        }
        return res * res;
    }
};
