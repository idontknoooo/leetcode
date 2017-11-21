// class Solution {
// public:
//     bool isPowerOfFour(int num) {
//         return ((num-1)&num)==0 && (num-1)%3==0;
//     }
// };

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==1) return true;
        if(num<1) return false;
        int n = num;
        while(n%4==0 && n>1)
            n /= 4;
        return n==1? true : false;
    }
};