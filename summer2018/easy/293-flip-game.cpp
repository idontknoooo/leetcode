class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> vec; 
        string tmp = s;
        for(int i = 1; i < s.length(); ++i){
            tmp = s;
            if(s[i]==s[i-1] && s[i]=='+'){
                tmp[i] = tmp[i-1] = '-';
                vec.push_back(tmp);
            }
        }
        return vec;
    }
};
