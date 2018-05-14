class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int slow = 1, fast = 2;
        for(int i = 3; i <= n; ++i){
            int tmp = slow;
            slow    = fast;
            fast    = tmp + slow;
        }
        return fast;
    }
};
