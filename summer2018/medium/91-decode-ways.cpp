// 4ms
class Solution {
public:
   int numDecodings(string s) {
        if(0 == s.size()) return 0;
        int dp1 = 1;
        int dp2 = '0' == s[0] ? 0 : 1;
        int res = dp2;
        for (int i = 1; i < s.size(); i++)
        {
            res = ('0' == s[i]) ? 0 : dp2;
            res = ('1' == s[i-1] || ('2' == s[i-1] && s[i] < '7')) ? res+dp1 : res;
            dp1 = dp2;
            dp2 = res;
        }
        
        return res;
    }
};


// 2ms
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        int pre = 1, cur = 1;
        for(int i = 1; i < s.size(); ++i) {
            int tmp;
            if(s[i] == '0') {
                if(s[i - 1] == '1' || s[i - 1] == '2') tmp = pre;
                else return 0;
            }else {
                if(s[i - 1] == '1' && s[i] <= '9' || s[i - 1] == '2' && s[i] <= '6') {
                    tmp = cur + pre;
                }else {
                    tmp = cur;
                }
            }
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};

// 3ms
class Solution {
public:
    int numDecodings(string s) {
        // Use DP, dp[i] means the number of ways to decode s[0, i)
        // So we have dp[0] = 1, dp[1] = s[1] == '0' ? 0 : 1
        // Further optimize the dp array to two variables.
        if (s.empty()) return 0;
        
        int n = s.size();
        int var1 = 1; // Ways to decode empty string
        int var2 = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            int num1 = s[i-1] - '0';
            int num2 = stoi(s.substr(i - 2, 2));
            int tmp = 0;
            if (num1 >= 1 && num1 <= 9)
                tmp += var2;
            if (num2 >= 10 && num2 <= 26)
                tmp += var1;
            var1 = var2;
            var2 = tmp;
        }
        return var2;
    }
};
