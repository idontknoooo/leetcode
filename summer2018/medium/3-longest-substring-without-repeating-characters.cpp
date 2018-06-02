// My solution 42ms beat 47%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int slow = 0, fast = 0, max_len = 0;
        um[s[slow]] = slow;
        
        for(; fast < s.length(); ){
            ++fast;
            max_len = max(max_len, fast - slow);
            
            if(um.find(s[fast]) != um.end()) 
                slow = max(slow, um[s[fast]] + 1);
            
            um[s[fast]] = fast;
        }
        return max_len;
    }
};


// 29ms solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dp(256,-1);
        int start=-1,maxlen=0;
        for(int i=0;i<s.size();i++){
            if(dp[s[i]]>start){
                start=dp[s[i]];
            }
            dp[s[i]]=i;
            maxlen=max(maxlen,i-start);
        }
        return maxlen;
    }
};
