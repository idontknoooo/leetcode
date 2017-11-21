class Solution {
public:
    string reverseString(string s) {
        // std::string tmp = "";
        // for(int i = s.length()-1; i >= 0; --i)
        // {
        //     tmp += s[i];
        // }
        // return tmp; 
        return string(s.rbegin(), s.rend());
    }
};