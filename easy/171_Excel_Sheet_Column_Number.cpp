class Solution {
public:
    int titleToNumber(string s) {
        int re = 0;
        for(int i = s.length()-1; i >=0; --i)
            re += pow(26, s.length()-1-i)*(s[i]-'A'+1);
        return re;
//         int result = 0;
// for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
// return result;
    }
};

// Same speed but much faster
// Horner's Algorithm 秦九韶算法
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char c:s) {
        	// res = 26*re + c-'A'+1;
            res *= 26;
            res += c - 'A' + 1;
        }
        return res;
    }
};