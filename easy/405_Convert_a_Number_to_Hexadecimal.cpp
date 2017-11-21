// const string HEX = "0123456789abcdef";
// class Solution {
// public:
//     string toHex(int num) {
//         if (num == 0) return "0";
//         string result;
//         int count = 0;
//         while (num && count++ < 8) {
//             result = HEX[(num & 0xf)] + result;
//             num >>= 4;
//         }
//         return result;
//     }
// };
class Solution {
public:
    string toHex(long num) {
        if (num == 0) { return "0"; }    
        
        int count = 0;
        string res = "";
        while (num && count++ < 8) {
            res = numMap[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }

private:
    const string numMap = "0123456789abcdef";
};