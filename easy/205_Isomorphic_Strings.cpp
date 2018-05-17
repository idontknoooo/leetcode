class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map_s[128] = { 0 };
        char map_t[128] = { 0 };
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            // for existed char, same char need to have same position, otherwise not isomorphic
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1; // Mark the position of it, and avoid 0
            map_t[t[i]] = i+1; 
        }
        return true;   
    }
};
