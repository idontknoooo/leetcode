// my solution 5ms
class Solution {
    vector<string> vec = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    string morse(string s) {
        string ans = "";
        for(char c : s) 
            ans += vec[c - 'a'];
        return ans;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string, int> um;
        for(int i = 0; i < words.size(); ++i) 
            um[morse(words[i])]++;
        return um.size();
    }
};
