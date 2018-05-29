// 54 ms
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1, pre = 0, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cur++;
            else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur, pre);
    }
};

// 40 ms
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        if(!n || n==1) return 0;
        char prev = s[0];
        int prev_c = 0, cur_c=1, count = 0;
        for(int i = 1; i< n;i++){
            if(s[i] == prev)cur_c += 1;
            else{
                prev_c = cur_c;
                cur_c = 1; 
            }
            if(prev_c >= cur_c) count++;
            prev = s[i];
        }
        return count;
    }
};
