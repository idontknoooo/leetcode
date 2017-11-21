class Solution {
public:
// bool wordPattern(string pattern, string str) {
//         istringstream strcin(str);
//         string s;
//         vector<string> vs;
//         while(strcin >> s) vs.push_back(s);
//         if (pattern.size() != vs.size()) return false;
//         map<string, char> s2c;
//         map<char, string> c2s;
//         for (int i = 0; i < vs.size(); ++i) {
//             if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
//                 s2c[vs[i]] = pattern[i]; 
//                 c2s[pattern[i]] = vs[i]; 
//                 continue; 
//             }
//             if (s2c[vs[i]] != pattern[i]) return false;
//         }
//         return true;
//     }
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> tables1;
        unordered_set<string> tables2;
        stringstream ss(str);
        string tmp;
        int index = 0;
        bool res = false;
        
        while (getline(ss, tmp, ' ')) {
            if (index == pattern.size()) {
                return res;
            }
            if (tables1.find(pattern[index]) != tables1.end() && tables1[pattern[index]] != tmp) {
                return res;
            }
            if (tables1.find(pattern[index]) == tables1.end() && tables2.count(tmp) > 0) {
                return res;
            }
            tables1[pattern[index++]] = tmp;
            tables2.insert(tmp);
        }
        
        return res = index == pattern.size();
    }
};