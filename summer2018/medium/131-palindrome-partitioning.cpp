//  7ms
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        dfs(s, 0, v, res);
        return res;
    }
    
    void dfs(string s, int pos, vector<string>& v, vector<vector<string>>& res){
        if(pos >= s.size()){
            res.push_back(v);
            return;
        }
        
        for(int i = pos; i < s.size(); i++){
            int l = pos, r = i;
            bool b = true;
            while(l < r && b) if(s[l++] != s[r--]) b = false;
            if(b){
                v.push_back(s.substr(pos, i - pos + 1));
                dfs(s, i + 1, v, res);
                v.pop_back();
            }
        }
    }
};

// 6ms
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string>>& ret) {
        if (index == s.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
