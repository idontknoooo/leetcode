class Solution {
public:
    bool isPalindrome(int x) {
        if(!(x%10) && x > 1) return false;
        int tmp = 0;
        while(x > tmp){
            tmp = tmp*10 + x%10;
            x  /= 10;
        }
        return (x == tmp) || (x == tmp/10);
    }
};
