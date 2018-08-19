class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length()-1, j = b.length()-1;
        string result = "";
        while(i >= 0 || j >=0){
           int tmp = carry;
           if(i >= 0) tmp += a[i--] - '0';
           if(j >= 0) tmp += b[j--] - '0';
           if(tmp > 1) {
               carry = 1;
               result = to_string(tmp%2) + result;
           } else {
               result = to_string(tmp) + result;
               carry = 0;
           }
        }
        if(carry) return "1" + result;
        return result;
    }
};
