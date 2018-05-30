class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        vector<int>v(n + 1);
        string res = "";
        for(auto s: words){
            auto pos = S.find(s);
            while(pos != string::npos){
                v[pos]++;
                v[pos + s.size()]--;
                pos = S.find(s, pos + 1);
            }
        }
        int pre = 0, cur = 0;
        for(int i = 0; i < n + 1; i++){
            cur = pre + v[i];
            if(pre == 0 && cur > 0) res += "<b>";
            else if(pre > 0 && cur == 0) res += "</b>";
            if(i < n) res.push_back(S[i]);
            pre = cur;
        }
        return res;
    }
};

class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        set<string> dict(words.begin(), words.end());
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            for (int j = i; j - i < 10 && j < n; j++) {
                if (!dict.count(s.substr(i, j + 1 - i))) continue;
                for (int k = i; k <= j; k++)
                    b[k]++;
            }
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (b[i] && (i == 0 || !b[i - 1])) res += "<b>";
            res += s[i];
            if (b[i] && (i == n - 1 || !b[i + 1])) res += "</b>";
        }
        return res;
    }
};
