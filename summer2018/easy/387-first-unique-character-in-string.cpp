// 39ms
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnts(128, 0);
        for(auto c : s) {
            ++cnts[c];
        }
        for(int i = 0; i < s.size(); ++i) {
            if (cnts[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

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
