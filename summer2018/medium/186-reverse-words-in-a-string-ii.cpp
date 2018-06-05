// 36ms
class Solution {
public:
    void reverseWords(vector<char>& str) {
        for(int i = 0; i < str.size(); i++){
            int j = i + 1;
            while(j < str.size() && str[j] != ' ') j++;
            int a = i, b = j - 1;
            while(a < b) swap(str[a++], str[b--]);
            i = j;
        }
        reverse(str.begin(), str.end());
    }
};


// 37ms
class Solution {
public:
    void reverseWords(vector<char> &s) {
        int left = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, left, i - 1);
                left = i + 1;
            }
        }
        reverse(s, 0, s.size() - 1);
    }
    void reverse(vector<char> &s, int left, int right) {
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left; --right;
        }
    }
};
