class Solution {
public:
    bool canPermutePalindrome(string s) {
        // bitset<256> b;
        // for (char c : s)
        //     b.flip(c);
        // return b.count() < 2;
        if(s == "") return false;
        int map[128] = {0};
        int cnt = 0;
        for(char c : s)
        {
            if((++map[c]) & 1) ++cnt;
            else --cnt;
        }
        
        return cnt <= 1;
    }
};