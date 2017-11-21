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