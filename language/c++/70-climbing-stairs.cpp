// 0ms
class Solution {
public:
    int climbStairs(int n) {
        if( n == 1 ) return 1;
        else if( n == 2 ) return 2;
        int first = 1, second = 2;
        int tmp = first;
        while( n > 2 ) {
            tmp = second;
            second += first;
            first = tmp;
            --n;
        }
        return second;
    }
};
