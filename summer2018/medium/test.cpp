#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string addition(string num1, string num2) {
    int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
    string ans = "";
    while(i >= 0 || j >= 0) {
        int tmp = carry;
        if(i >= 0) tmp += num1[i--] - '0';
        if(j >= 0) tmp += num2[j--] - '0';
        carry = tmp>9? 1 : 0;
        ans.append(to_string(tmp%10));
    }
    if(carry) ans.append("1");
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
  cout << addition("123", "459") << " " << 123+459 << endl;;
}
