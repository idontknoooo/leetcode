// 40ms
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<string> zigTab(numRows, "");
        int circle = 2*numRows - 2;
        for (int i = 0; i < s.length(); ++i) {
            if (i % circle < numRows) zigTab[i % circle] += s[i];
            else zigTab[circle - i%circle] += s[i];
        }
        string result = "";
        for (auto val : zigTab) result += val;
        return result;
    }
};
