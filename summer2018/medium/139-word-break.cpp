// beat 99%
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> break_possible(s.size() + 1, true);
    
    return word_break(s, wordDict, 0, break_possible);
  }
private:
  bool word_break(string s, const vector<string>& dict, int s_i, 
      vector<bool>& break_possible) {
    if (s_i == s.size()) {
      return true;
    }
    
    for (const auto& word : dict) {
      int next_position = s_i + word.size();
      if (next_position > s.size()) {
        continue;
      }
      
      if (break_possible[next_position] && s.substr(s_i, word.size()) == word) {
        // fall through when we discover word break is possible
        if (word_break(s, dict, next_position, break_possible)) {
          return true;
        }
      }
    }
    
    break_possible[s_i] = false;
    return false;
  }
};

//  4ms
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // value at index i indicates whether substring of s up to but excluding s[i] can be broken by wordDict
        vector<bool> canBreak( s.length() + 1, false );
        canBreak[0] = true;

        for ( size_t i = 1; i <= s.length(); i++ )
        {
            for ( string word : wordDict )
            {
                size_t len = word.length();
                if ( len > i || !canBreak[i - len] )
                {
                    continue;
                }
                if ( s.substr( i - len, len ) == word )
                {
                    canBreak[i] = true;
                    break;
                }
            }
        }

        return canBreak.back();        
    }
};
