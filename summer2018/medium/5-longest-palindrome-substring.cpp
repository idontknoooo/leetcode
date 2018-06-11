// Expand method
// aba : find a position expand left & right. Differnt char
// abba: find 2 position expand left & right. Same chars
class Solution {
public:
    string longestPalindrome(string s) {
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
          if (s.size() - i <= max_len / 2) break;
          int j = i, k = i;
          // Solve "abba" problem even number same chars
          while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
          i = k+1; // Check next char, expand left & right of it
          while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
          int new_len = k - j + 1; // Calculate current length
          if (new_len > max_len) { min_start = j; max_len = new_len; }
        }
        return s.substr(min_start, max_len);
    }
};
