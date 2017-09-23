class Solution {
public:
    int mySqrt(int x) {
        double ans    = x;
        double delta  = 0.0001;
        while (abs(pow(ans, 2) - x) > delta) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};
// 3 ms
class Solution {
public:
    int mySqrt(int x) {
		// A better approach to time
        if(x==1) return 1;
        double ans    = x/2; // use x/2
        double delta  = 0.0001;
        while (abs(pow(ans, 2) - x) > delta) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};
