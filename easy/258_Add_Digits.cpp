#include <string>
class Solution {
public:
    int addDigits(int num) {
        // string s = to_string(num);
        // int val = 0;
        // if(s.length()==1)
        // {
        //     return num;
        // }
        // else
        // {
        //     for(int i = 0; i < s.length(); ++i)
        //     {
        //         val += stoi(s.substr(i,1));
        //     }
        // }
        // return addDigits(val);
        return 1 + (num - 1) % 9;
    }
};