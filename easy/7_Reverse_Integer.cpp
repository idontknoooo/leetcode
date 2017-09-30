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
