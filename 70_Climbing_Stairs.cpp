class Solution {
public:
    int climbStairs(int n) {
		// a: 2 steps to new step
		// b: 1 step to new step
        int a = 1, b = 1;
        while (n--)
            a = (b += a) - a;
        return a;
    }
};
