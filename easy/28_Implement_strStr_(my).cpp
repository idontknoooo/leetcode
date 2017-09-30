class Solution {
public:
    int strStr(string haystack, string needle) {
        
        return haystack.find(needle);
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        if(!len) return 0;
        for(int i = 0; i < haystack.length(); ++i){
            try{
                if(!haystack.substr(i, len).compare(needle))
                    return i;
            }
            catch(int err){
                return -1;
            }
        }
        return -1;
    }
};
