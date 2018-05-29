// 45ms
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                res = w.size() > res.size() ? w : res;
                built.insert(w);
            }
        }
        return res;
    }
};

// 34ms
class Solution {
public:
    string longestWord(vector<string>& words) {
      unordered_set<string> us(words.begin(), words.end());
      string ret;
      for (const auto& w : words) {
        if (ret.size() > w.size() || (ret.size() == w.size() && ret < w)) continue;
        if (w.size() == 1) ret = w;
        else for (int k = w.size() - 1; k >= 1; --k) {
          if (!us.count(w.substr(0, k))) break;
          if (k == 1) ret = w;
        }
      }
      return ret;
    }
};

