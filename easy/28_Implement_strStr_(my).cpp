class Solution {
public:
    int strStr(string haystack, string needle) {

        int stacksize = haystack.size();
        int needlesize = needle.size();
        if(stacksize < needlesize) return -1;
        for(int i = 0; i <= stacksize-needlesize; i++)
        {
            // once doesn't match, make j = 0 and increment i
            int j=0;
            while(j!=needlesize && haystack[i+j]==needle[j]) j++;
            if(j==needlesize) return i;            
        }
        return -1;
    }
};
// Use find() kinda like cheat
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        return haystack.find(needle);
    }
};
// My first version, which is slow since it checks everything
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

