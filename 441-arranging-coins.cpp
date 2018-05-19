class Solution {
public:
    int arrangeCoins(int n) {
        if(!n) return 0;
        int i = 1;
        while(n > 0){
            n -= i++;
            if(i > n) return i-1;
            if(i == n) return i;
        }
    }
};


class Solution {
public:
    // k(k+1)/2 = n
    int arrangeCoins(int n) {
        return floor(sqrt(8*static_cast<double>(n) + 1)/2.0 - 0.5);
    }
};
