#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  string s = "abba";
  unordered_map<char, int> um;
  int slow = 0, fast = 0, max_len = 0;
  um[s[slow]] = slow;
  for(; fast < s.length(); ){
    ++fast;
    cout << slow << " " << fast << endl;
    if(um.find(s[fast]) == um.end()) {
      um[s[fast]] = fast;
      max_len = max(max_len, fast - slow);
    } else {
      max_len = max(max_len, fast - slow);
      slow = max(slow, um[s[fast]] + 1);
      um[s[fast]] = fast;
    }
  }
  cout << max_len << endl;
  return max_len;
}

