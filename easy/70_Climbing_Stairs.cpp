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
// Most intuitive way of thinking
int climbStairs(int n){

 	int one = 1, two = 2;
 	if(n==1) return one;
 	if(n==2) return two;
 	int re = 0;
 	for(int i = 3; i <= n; ++i){
 		re = one + two;
 		one = two;
 		two = re;
 	}		
 	return re;
 } 