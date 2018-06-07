class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>0){
            if(n==1) return true;
            if(n%2) return false;
            n /= 2;
        }
        return false;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {  
        return (n <= 0) ? false : (n == (n & (-n))); //n & -n returns the number with only the last 1 bit to be 1
    }
};
