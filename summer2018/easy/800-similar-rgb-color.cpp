// My solution 6ms beat 100%
class Solution {
    unordered_map<char, int> um = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}
    };
    map<int, string> m = {
        {0, "00"}, {17, "11"}, {34, "22"}, {51, "33"}, {68, "44"}, {85, "55"}, {102, "66"}, {119, "77"}, {136, "88"}, {153, "99"}, {170, "aa"}, {187, "bb"}, {204, "cc"}, {221, "dd"}, {238, "ee"}, {255, "ff"}
    };
public:
    int hex2decimal(string s) {
        int num = 0;
        for(int i = 0; i < s.length(); ++i) 
            num = num*16 + um[s[i]];
        return num;
    }
    string closestShorthand(int decimal) {
        string sh = "";
        int closest = INT_MAX; 
        for(auto p : m) {
            if(abs(decimal - p.first) < closest) {
                closest = abs(decimal - p.first);
                sh = p.second;
            }
        }
        return sh;
    }
    string similarRGB(string color) {
        if(color[1]==color[2] && color[3]==color[4] && color[5]==color[6]) return color;
        string ans = "#";
        int decimal = 0;
        for(int i = 1; i < color.length(); i += 2) {
            decimal = hex2decimal(color.substr(i, 2));
            ans += closestShorthand(decimal);
        }
        return ans;
    }
};
// 7ms
class Solution {
public:
    string helper(string str) {
        string dec_to_hex = "0123456789abcdef", res = "";

        int dec_num = stoi(str, nullptr, 16);
        int q = dec_num / 17;
        if ((dec_num % 17) > 8) q = q + 1;
        res = res + dec_to_hex[q] + dec_to_hex[q];
        return res;
    }

    string similarRGB(string color) {
        return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
    }
};
