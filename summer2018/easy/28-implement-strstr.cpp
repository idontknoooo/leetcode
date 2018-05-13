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


// A much cleaner way
// If found, go out of the loop
// If not, go back to next letter keep finding,
// If not in the end, j will equal 0, and i will be m, thus i-j > m-n
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, m = haystack.length(), n = needle.length();
        while(i < m && j < n){
            if(haystack[i]==needle[j]) ++i, ++j;
            else i -= j-1, j = 0;
        }
        return (i-j > m-n)? -1 : i-j;
    }
};
