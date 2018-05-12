class Solution {
public:
    int reverse(int x) {
        long num = 0;
        while(x){
            num  = num * 10  +  (x % 10); 
            x   /= 10;
        }
        
        return (num > INT_MAX || num < INT_MIN)? 0 : (int)num;
    }
};
