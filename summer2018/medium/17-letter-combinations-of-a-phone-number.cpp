// my solution 3ms, beat 91% DFS
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
// DFS: Recursion
// BFS: Use queue

// 2ms solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        // if (digits.find("0") != NULL || digits.find("1") != NULL || digits.find("*") != NULL || digits.find("#") != NULL) {
        //     return result;
        // }
        vector<string> map = buildMap();
        for (int i = 0; i < digits.size(); i++) {
            int digit = digits[i] - '0';
            addDigit(digit, result, map);
        }
        return result;
    }
    
    void addDigit(int digit, vector<string>& result, vector<string>& map) {
        if (map[digit].size() == 0) {
            return;
        }
        if (result.size() == 0) {
            for (int i = 0; i < map[digit].size(); i++) {
                string x = "";
                x = x + map[digit][i];
                result.push_back(x);
            }
        } else {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                //取值
                string temp = result[0];
                //erase
                result.erase(result.begin());
                //添加
                for (int j = 0; j < map[digit].size(); j++) {
                    string x(temp);
                    x = x + map[digit][j];
                    result.push_back(x);
                }
            }
        }
    }
    
    vector<string> buildMap() {
        vector<string> map(10);
        map[0] = "";
        map[1] = "";
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        return map;
    }
};
