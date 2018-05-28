// My solution
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n&1, cur = 0;;
        n >>= 1;
        while(n) {
            cur = n&1;
            if(!(cur ^ pre)) return false;
            pre = cur;
            n >>= 1;
        }
        return true;
    }
};


// Other solution
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = n^n>>1; // get 1111 s if alternating bits
        return !(temp & temp+1); // 01111 & 10000 -> 00000
    }
};
