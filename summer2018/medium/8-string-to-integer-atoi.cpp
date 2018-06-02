// My solution 36ms beat 18%
class Solution {
public:
    string leadingSpace(string s) {
        for(int i = 0; i < s.length(); ++i) 
            if(s[i] != ' ') return s.substr(i, s.length() - i);
        return "";
    }
    string getNumber(string s) {
        string ans = "";
        if(!s.length() || (s.length() >= 2 && !isdigit(s[0]) && !isdigit(s[1]))) return "";
        int i = 0;
        if(s[0] == '-' || s[0] == '+') ans += s[0], i = 1;
        for(; i < s.length() && isdigit(s[i]); ++i) ans += s[i];
        return ans;
    }
    int str2int(string s) {
        long num = 0;
        if(!s.length()) {
            return 0;
        } else {
            int i = 0;
            bool pn = 1;
            if(s[0] == '-' || s[0] == '+') {
                i = 1;
                pn = (s[0] == '-')? 0 : 1;
            }
            for(; i < s.length(); ++i) {
                num = num * 10 + s[i] - '0';
                if(pn && num > INT_MAX) return INT_MAX;
                else if(!pn && num + INT_MIN > 0) return INT_MIN;
            }
            if(!pn) num = -1 * num;
            return num;
        }
    }
    int myAtoi(string str) {
        string tmp = leadingSpace(str);
        tmp = getNumber(tmp);
        return str2int(tmp);
    }
};


// 25ms
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int n = str.size();
        int i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            i++;
            sign = -1;
        }
        for (; i < n; i++) {
            if (str[i] < '0' || '9' < str[i]) return res * sign;
            else {
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
            }
            res = res * 10 + str[i] - '0';
        }
        return res * sign;
    }
};
