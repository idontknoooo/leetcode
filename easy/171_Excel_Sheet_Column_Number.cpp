class Solution {
public:
    int titleToNumber(string s) {
        int re = 0;
        for(int i = s.length()-1; i >=0; --i)
            re += pow(26, s.length()-1-i)*(s[i]-'A'+1);
        return re;
//         int result = 0;
// for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
// return result;
    }
};