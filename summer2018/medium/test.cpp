#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
          if (s.size() - i <= max_len / 2) break;
          int j = i, k = i;
          while (k < s.size()-1 && s[k+1] == s[k]) {
            cout << "Same: " << s[k+1] << " " << s[k] << endl;
            ++k; // Skip duplicate characters.
          } 
          cout << i << " " << j-1 << " " << k+1 << endl;  
          i = k+1;
          while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { 
            cout << "Expand: " << s[k+1] << " " << s[j-1] << endl;
            ++k; --j; 
          } // Expand.
          int new_len = k - j + 1;
          if (new_len > max_len) { min_start = j; max_len = new_len; }
          cout << "Len: " << new_len << " " << max_len << endl;
          cout << endl;
        }
        return s.substr(min_start, max_len);
    }
};

int main() {
    //Solution s;
    //cout << s.longestPalindrome("aaabbccbbfg") << endl;
    cout << 0 << " " << ~0 << endl;
    int a = 1;
    while(a) {
      int tmp = a & 1;
      cout << tmp << endl;
      a <<= 1;
    }
}
