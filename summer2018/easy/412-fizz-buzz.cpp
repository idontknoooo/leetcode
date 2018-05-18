class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec;
        string tmp = "";
        for(int i = 1; i <= n; ++i){
            tmp = "";
            if(!(i%3)) tmp += "Fizz";
            if(!(i%5)) tmp += "Buzz";
            if(tmp=="") tmp = to_string(i);
            vec.push_back(tmp);
        }
        return vec;
    }
};
