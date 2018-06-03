// My solution O(c); scalable 66ms
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        map<int, string> m = {
            {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}
        };
        vector<int> vec = {1000, 500, 100, 50, 10, 5, 1};
        int count = 0;
        for(int i = 0; i < vec.size(); i+=2) {
            if(num >= vec[i]) {
                count = num / vec[i];
                num   = num - count * vec[i];
                if(count != 4 && count != 9) {
                    if(count >= 5) {
                        ans   += m[vec[i-1]];
                        count -= 5;
                    }
                    //for(int j = 0; j < count; ++j) ans += m[vec[i]];
                    ans += string(count, m[vec[i]][0]);
                } else if (count == 4) ans += m[vec[i]] + m[vec[i-1]];
                else ans += m[vec[i]] + m[vec[i-2]];
            }
            count = 0;
        }
        return ans;
    }
};

// other solution 61ms
class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
