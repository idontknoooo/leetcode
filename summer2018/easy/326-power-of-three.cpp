class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>1){
            if(!(n%3)) n /= 3;
            else return false;
        }
        return n==1;
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double x = log(n) / log(3);
        return (abs(x - ceil(x)) < 1e-10);
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 is 3^19,  3^20 is bigger than int  
        return (n>0 && !(1162261467%n));
    }
};
