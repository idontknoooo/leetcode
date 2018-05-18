class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream ss(str);
        string s;
        vector<string> v;
        while (ss >> s) {
            v.push_back(s);
        }
        
        if (v.size() != pattern.size()) {
            return false;
        }
        
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < v.size(); ++i) {
            if (s2c[v[i]] == 0 && c2s[pattern[i]] == ""){ 
                s2c[v[i]] = pattern[i];
                c2s[pattern[i]] = v[i];
                continue;
            }
            if (s2c[v[i]] != pattern[i]) {
                return false;
            }
        }
        
        return true;
    }
};


class Solution {
public:
    bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}
};
