// My solution 6ms
class Solution {
public:
    string toGoatLatin(string S) {
        int word_c = 1;
        stringstream ss(S);
        string ans = "", word = "", new_w = "", vowel = "aeiouAEIOU";
        while(getline(ss, word, ' ')) {
            if(vowel.find(word[0]) != string::npos) {
                new_w = word + "ma";
            } else {
                new_w = word.substr(1, word.length()-1) + word[0] + "ma";
                cout << new_w << endl;
            }
            for(int i = 0; i < word_c; ++i) new_w += "a";   
            ans += " " + new_w;  
            ++word_c;
        }
        return ans.substr(1, ans.length()-1);
    }
};
