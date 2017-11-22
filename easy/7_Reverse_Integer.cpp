#include <iostream>
#include <climits> // For INT_MIN & INT_MAX
using namespace std;
// Think in a computer way; not a mathematician way
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
class Solution {
public:
    int reverse(int x) {
        long long re = 0;
        x>0? re = 0 : re = 1;
        string tmp = to_string(x);
        string str = "";
        for(int i = 0; i < tmp.length(); ++i){
            str = tmp.substr(i,1) + str;
        }
        re = x>0? stoll(str):0-stoll(str);
        return (re<INT_MIN || re>INT_MAX) ? 0 : re;
    }
};