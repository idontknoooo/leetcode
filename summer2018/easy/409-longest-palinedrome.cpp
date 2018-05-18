class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        int odd = 0, sum = 0;
        for(char c : s) um[c]++;
        for(auto p : um){
            if(p.second%2) odd = 1, p.second--;
            sum += p.second;
        }
        return sum + odd;
    }
};
