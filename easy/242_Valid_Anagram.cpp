class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     if (s.length() != t.length()) return false;
    //     int n = s.length();
    //     unordered_map<char, int> counts;
    //     for (int i = 0; i < n; i++) {
    //         counts[s[i]]++;
    //         counts[t[i]]--;
    //     }
    //     for (auto count : counts)
    //         if (count.second) return false;
    //     return true;
    // }
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        int count[26] = {};
        for (auto ch : s) {
            count[ch-'a']++;
        }
        
        for (auto ch : t) {
            count[ch-'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isAnagram(string s, string t) { 
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t; 
//     }
// };