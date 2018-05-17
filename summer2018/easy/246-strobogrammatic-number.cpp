class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> um = {
            {'6','9'}, {'9','6'}, {'8','8'}, {'0','0'}, {'1','1'},
            {'2','-'}, {'3','-'}, {'4','-'}, {'5','-'}, {'7','-'}
        };
        //if(um.find(num[num.length()/2])==um.end()) return false;
        int i = 0, j = num.length()-1;
        while(i <= j){
            if(um[num[i++]]!=num[j--]) return false;
        }
        return true;
        
    }
};
