// 14ms 77%
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
    
    int parseExpr(const string &s, int &i) {
        const int N = s.size();
        char op = '+'; // 上一个未处理操作
        vector<int> nums;
        for (; i < N; i++) {
            if (s[i] == ' ') continue;
            int num = 0;
            if (isdigit(s[i])) {
                while (i < N && isdigit(s[i]))
                    num = num * 10 + s[i++] - '0';
            }
            // 遇到新操作+-*/或结束，处理上一个操作op
            if (op == '+') nums.push_back(num);
            else if (op == '-') nums.push_back(-num);
            else if (op == '*') nums.back() *= num;
            else if (op == '/') nums.back() /= num;
            op = s[i];
        }
        
        int ans = 0;
        for (int num : nums) 
            ans += num;
        return ans;
    }
};
