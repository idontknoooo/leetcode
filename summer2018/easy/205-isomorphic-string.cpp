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
