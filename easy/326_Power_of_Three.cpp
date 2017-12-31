// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n<1) return false;
//         else
//             return n%3==0 && isPowerOfThree(n/3) || n==1;
//     }
// };

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n==0) return false;
        while(n>=1 && !(n%3))
        {
            n /= 3;
        }
        return n==1? true : false;
    }
};

// If n is the power of three, then it must be able to divisable by the largest power of 3
// For example:
// n = 3^2 = 9
// x = 3^100 = I dont know. But x%n == 0
// To get the Max integer of power of 3, reverse engineering!
// 3^some_num = INT_MAX
// then some_num = log(INT_MAX) / log(3)
// and convert to int
bool isPowerOfThree(int n) {
        if (n<=0) return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return (t%n == 0);
    }
