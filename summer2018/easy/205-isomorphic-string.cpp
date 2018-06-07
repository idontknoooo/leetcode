class Solution {
public:
    // Remap a string using letters start from 'a'
    string mapping(string s){
        unordered_map<char, char> um;
        int pos = 0;
        for(int i = 0; i < s.length(); ++i){
            if(um.find(s[i])==um.end()) 
                um[s[i]] = (char)('a' + pos++);
            s[i] = um[s[i]];
        } 
        return s;
    }
    bool isIsomorphic(string s, string t) {
        //if(s.length() != t.length()) return false;
        return mapping(s) == mapping(t);
    }
};

// 7ms
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0};
        int m2[256] = {0};
        int n =s.size();
        
        for(int i=0;i<n;i++){
            if(m1[s[i]]!=m2[t[i]])
                return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
        
    }
};
