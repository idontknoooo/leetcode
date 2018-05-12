class Solution {
public:
    bool isValid(string s) {
        map<char, char> m = {
            {'}', '{'}, {']', '['}, {')', '('}
        };
        stack<char> stk;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if(stk.empty() || stk.top() != m[s[i]])
                    return false;
                else
                    stk.pop();
            } else 
                stk.push(s[i]);
        }
        return stk.empty();
    }
};
