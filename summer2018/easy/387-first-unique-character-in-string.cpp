class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> um;
        for(int i = 0; i < s.length(); ++i){
            if(um.find(s[i])==um.end()) um[s[i]] = i;
            else um[s[i]] = -1;
        }
        int pos = INT_MAX;
        for(auto p : um){
            if(p.second != -1 && p.second < pos)
                pos = p.second;
        }
        return pos==INT_MAX? -1 : pos;
    }
};
