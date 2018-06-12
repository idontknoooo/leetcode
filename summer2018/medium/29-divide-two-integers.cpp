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

/*
  e.g.
    dividend = 15, divisor = 4;
    dd = 15
    ds = 16, current = 4,

    15 > 16? No, ds = 8, current = 2; | ans = 0 --- 000
    15 > 8? Yes, ds = 4, current = 1; | ans = 2 --- 010 | dd = 15 - 8 = 7
    7  > 4? Yes, ds = 2, current = 0; | ans = 3 --- 011 | dd = 7 - 4  = 3
    current==0, break
    
    return ans, which is 3
  ----------------------------------------------------------------------
  e.g.
    dividend = 15, divisor = 6;
    dd = 15
    ds = 24, current = 4,

    15 > 24? No, ds = 12, current = 2; | ans = 0 --- 000
    15 > 12? Yes, ds = 6, current = 1; | ans = 2 --- 010 | dd = 15 - 12 = 3
    3  > 6?  No, ds = 3, current = 0;  | ans = 2 --- 010 |
    current==0, break
    
    return ans, which is 2
*/
class Solution {
public:
    
    int divide(int dividend, int divisor) {
        
       //if (divisor == 0)    return INT_MAX;      
       if (divisor == -1 && dividend == INT_MIN) return  INT_MAX;  // Handle negative INT_MIN. Return INT_MAX directly
        
       int negative = ((dividend > 0) ^ (divisor > 0)); // Check if negative
       long dd = abs((long) dividend), ds = abs((long) divisor); 
       long current = 1, ans = 0;
        
       do {
            ds <<= 1;      // ds  = ds * 2
            current <<= 1; // cur = cur * 2
       } while (dd >= ds); // use 'current' to count the time of divisor

       while (current!=0) {
           if (dd >= ds) {
               dd -= ds;       // Decrease dd
               // Use | as plus operation because 'current' is always power of 2, its binary will start with 1 and follow a number of 0s. 
               // 4 | 2 == 4 + 2 since 100->4, 10->2, 4|2 -> 110 -> 6
               ans |= current; // here's key, it counts 2^n times of divisor and make divisor down graduately.
           }
           current >>= 1;      // decrease times
           ds >>= 1;           // decrease ds
       } 
       return negative? -ans:ans;       
    }
    
};
