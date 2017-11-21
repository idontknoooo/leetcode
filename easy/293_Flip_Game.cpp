class Solution {
public:
    // vector<string> generatePossibleNextMoves(string s) {
    //     vector<string> moves;
    //     int n = s.length();
    //     for (int i = 0; i < n - 1; i++) {
    //         if (s[i] == '+' && s[i + 1] == '+') { 
    //             s[i] = s[i + 1] = '-';
    //             moves.push_back(s);
    //             s[i] = s[i + 1] = '+';
    //         }
    //     }
    //     return moves;
    // }
     vector<string> generatePossibleNextMoves(string s) {
        vector<string> rslt;
        if (s.length() <= 1) return rslt;
        for (int i = 0; i < s.length() - 1; i++) {
            if ((s[i] == '+') && (s[i+1] == '+')) {
                s[i] = s[i+1] = '-';
                rslt.push_back(s);
                s[i] = s[i+1] = '+';
            }
        }
        
        return rslt;
    }
};