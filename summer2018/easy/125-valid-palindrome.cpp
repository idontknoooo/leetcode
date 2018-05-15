class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.length()-1;
        while(begin < end){
            if(isalnum(s[begin]) && isalnum(s[end]) && tolower(s[begin]) != tolower(s[end]))
                return false;
            else if(isalnum(s[begin]) && isalnum(s[end]) && tolower(s[begin]) == tolower(s[end])){
                ++begin, --end;
            }
            if(!isalnum(s[begin]))
                ++begin;
            if(!isalnum(s[end])) 
                --end;
        }
        return true;
    }
};
