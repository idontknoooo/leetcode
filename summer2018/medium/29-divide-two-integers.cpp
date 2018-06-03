// 18ms bitwise operation
class Solution {
public:
    int divide(int dividend, int divisor) {
           if (!divisor || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        int res = 0;
        long long dvd = labs(dividend);
        long long divi = labs(divisor);
        while (dvd >= divi) {
            long long temp = divi;
            long long t1 = 1;
            while (dvd >= (temp<<1)) {
                temp <<= 1;
                t1 <<=1;
            }
            dvd -= temp;
            res += t1;
        }
       return sign == 1 ? res : -res; 
     }
};

class Solution {
public:
    
    int divide(int dividend, int divisor) {
        
       if (divisor == 0)    return INT_MAX;      
       if (divisor == -1 && dividend == INT_MIN) return  INT_MAX;        
        
       int negative = ((dividend > 0) ^ (divisor > 0));
       long dd = abs((long) dividend), ds = abs((long) divisor); 
       long current =1,ans=0;
        
       do {
            ds <<= 1;
            current <<= 1;
       } while (dd >= ds); 

       while (current!=0) {
           if ( dd >= ds) {
               dd -= ds;
               ans |= current; // here's key, it counts 2^n times of divisor and make divisor down graduately.
              
           }
           current >>= 1;
           ds >>= 1;
       } 
       return negative? -ans:ans;       
    }
    
};
