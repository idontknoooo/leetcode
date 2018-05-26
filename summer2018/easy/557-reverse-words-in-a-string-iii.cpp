class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        for(; j < s.length();){
            if(s[j+1] == ' ' || j == s.length()-1){
                int a = i, b = j;
                char tmp = ' ';
                while(a < b){
                    tmp = s[a];
                    s[a++] = s[b];
                    s[b--] = tmp;
                }
                j+=2, i = j;
                continue;
            }
            ++j;
        }
        return s;
    }
};
