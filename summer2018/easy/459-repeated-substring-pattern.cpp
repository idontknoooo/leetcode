class Solution {
public:
    bool repeatedSubstringPattern(string str) 
    {
        return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
    }
};

// KMP
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if (len % 2 == 0 && s.substr(0, len / 2) == s.substr(len / 2, len / 2))
        {
            return true;
        }
        int i = 1, j = 0;
        vector<int> dp(len + 1, 0);
        
        while(i < len) {            
            if(s[i] == s[j]) {
                dp[++i] = ++j;
            }
            else if(j == 0) {
                i++;
            }
            else {
                j = dp[j];
            }
        }
        return dp[len] && dp[len] % (len - dp[len]) == 0;
    }
};
