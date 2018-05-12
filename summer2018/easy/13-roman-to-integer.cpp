class Solution {
public:
    int romanToInt(string s) {
        map<char, int> um {
          {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
        int total = 0;
        for(int i = 0; i < s.length()-1; ++i){
            if(um[s[i]] < um[s[i+1]])
                total -= um[s[i]]; 
            else 
                total += um[s[i]]; 
        }
        total += um[s[s.length()-1]];
        return total;
    }
};
