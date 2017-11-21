class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char, int> m;
        // for (auto &c : s) {
        //     m[c]++;
        // }
        // for (int i = 0; i < s.size(); i++) {
        //     if (m[s[i]] == 1) return i;
        // }
        // return -1;
        vector<int> count(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] -'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i] -'a'] == 1)
                return i;
        }
        return -1;
    }
};