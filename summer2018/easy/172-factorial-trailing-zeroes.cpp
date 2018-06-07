// slow recursive
class Solution {
public:
      int trailingZeroes(int n) {
          return n/5? n/5 + trailingZeroes(n/5):0;
      } 
};

// fast 4ms recursive
class Solution {
public:
    int trailingZeroes(int n) {
        int count_five = 0;  
        while ( n > 0) {  
            int k = n / 5;  
            count_five += k;  
            n = k;  
        }  
        return count_five;          
    }
};

// 5ms
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for(long long i=5; n/i>0; i*=5){
            result += (n/i);
        }
        return result;
    }
};
