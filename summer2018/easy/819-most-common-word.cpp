// My solution 7ms
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> um, ban_um;
        for(string s : banned) 
            ban_um[s] = 1;
        
        string word = "";
        for(int i = 0; i <= paragraph.length(); ++i) {
            if(isalpha(paragraph[i])) 
                word += tolower(paragraph[i]);
            else if (word != "" && !ban_um[word]) {
                um[word]++;
                word = "";
            } else 
                word = "";
        }
        
        string val = (*max_element(um.begin(), um.end(), [](auto p1, auto p2){return p1.second < p2.second;})).first;
        return val;
    }
};
