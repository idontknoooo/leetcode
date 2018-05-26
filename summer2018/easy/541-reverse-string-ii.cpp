// My solution 10 ms
class Solution {
public:
    void reverse(string& s, int i, int j){
        char tmp = ' ';
        if(j >= s.length()) j = s.length()-1;
        while(i < j){
            tmp = s[j];
            s[j--] = s[i];
            s[i++] = tmp;
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i += 2*k)
            reverse(s, i, i+k-1);
        return s;
    }
};


// 8 ms
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i += 2 * k)
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        return s;
    }
};
