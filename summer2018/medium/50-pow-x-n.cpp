// 9ms
class Solution {
public:
  double myPow(double x, int n) {
    bool negative = n < 0 ? true : false;
    if (x == 0) return 0;
    if (n == 0) return 1;

    long long nn = abs((long long)n);
    double res = 1;
    // nn = 6 3   1   0
    // x  = x x^2 x^4 x^8
    // res= 1 x^2 x^6 x^6

    // nn = 7 3   1   0
    // x  = x x^2 x^4 x^8
    // res= x x^3 x^7 x^7

    // nn = 8 4   2   1   0
    // x  = x x^2 x^4 x^8 x^16
    // res= 1 1   1   x^8
    for (int i = 0; i < 32; i++) {
      if (nn & 1) { // If odd number, res *= x, where x is current x power. This will make odd number same as odd-1, which is an even number
        res *= x;
      }
      nn >>= 1;
      x *= x;
    }
    return negative ? 1 / res : res;
  }
};

// 11ms
class Solution {
public:
    double myPow(double x, int n) {
        if(n==INT_MIN){
            double temp = myPow(x, n>>1);
            return temp*temp;
        }
        if(n<0) return 1/myPow(x, -n);
        if(n==0) return 1;
        double temp=myPow(x, n/2);
        if(n%2==0)
            return temp*temp;
        else
            return temp*temp*x;
    }
};
