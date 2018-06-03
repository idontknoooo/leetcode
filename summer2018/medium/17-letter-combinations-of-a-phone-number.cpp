// my solution 3ms, beat 91%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return {};
        vector<string> vec = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans(pow(4, digits.length()));
        
        int len = 1;
        for(int i = 0; i < digits.length(); ++i) {   // Iterate digits string
            string letter = vec[digits[i]-'0'-2];
            for(int prev_pos = 0; prev_pos < len; ++prev_pos) {
                string prev = ans[prev_pos];
                for(int letter_pos = 0; letter_pos < letter.length(); ++letter_pos) {
                    int pos = prev_pos + letter_pos * len;
                    ans[pos] = prev + letter[letter_pos];
                }
            }
            len *= letter.length();
        }
        
        // Eliminate empty
        ans = vector<string> (ans.begin(), ans.begin() + len);
        return ans;
    }
};
