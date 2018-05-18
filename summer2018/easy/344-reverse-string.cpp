class Solution {
public:
    string reverseString(string s) {
        string tmp = "";
        for(int i = s.length()-1; i >= 0; --i){
            tmp += s[i];
        }
        return tmp;
    }
};
