class Solution {
public:
    int mySqrt(int x) {
        double res = x / 2.0;
        while( abs(res*res - x) > 0.0001) {
            res = res - (res*res - x) / (2.0 * res);
        }
        return (int)res;
    }
};
