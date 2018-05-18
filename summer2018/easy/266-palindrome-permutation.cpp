class Solution {
public:
    bool canPermutePalindrome(string s) {
        int a[128] = { 0 };
        for(int i = 0; i < s.length(); ++i) a[s[i]]++;
        
        int odd = 0;
        for(int i = 0; i < 128; ++i) if(a[i]%2) if(++odd > 1) return false;
                
        return true;
    }
};
