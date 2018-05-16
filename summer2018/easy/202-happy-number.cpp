class Solution {
public:
    int sqr_sum(int n){
        int re = 0;
        while(n > 0){
            re += pow((n%10),2);
            n  /= 10;
        }
        return re;
    }
    bool isHappy(int n) {
        int fast = n;
        while(n){
            n = sqr_sum(n);
            fast = sqr_sum(fast);
            fast = sqr_sum(fast);
            if(n==1) return true;
            if(fast==n) return false;
        }
    }
};
