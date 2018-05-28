// My solution
class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> um;
        for(char c : moves){
            if(c=='U') um[c]++;
            if(c=='D') um['U']--;
            if(c=='L') um[c]++;
            if(c=='R') um['L']--;
        }
        return um['U'] == 0 && um['L'] == 0;
    }
};
