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


// Bitwise operation
class Solution {
public:
    bool isPowerOfFour(int num) {
        // first check only one bit is set:
        if ((num & (num -1)) != 0) return false;
        // next check if it's a bit in pos 1, 3, 5 ... 31
        if (num & 0x55555555) return true;
        return false;
    }
};

// Don't understand yet
class Solution {
public:
    bool isPowerOfFour(int num) {
        return ((num-1)&num)==0 && (num-1)%3==0;
    }
};