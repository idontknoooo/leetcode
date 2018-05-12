class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(haystack.length() < needle.length()) return 0;
        if(haystack.length() == needle.length() && haystack == needle) return 0;
        int len = needle.length();
        for(int i = 0; i < haystack.length() - len + 1; ++i){
            if(haystack.substr(i, len) == needle)
                return i;
        }
        return -1;
    }
};
