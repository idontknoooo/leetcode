class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        int accu = 0; 
        while(true){
            if((n - accu)/(9.0*digit) <= pow(10, digit - 1)) break;
            int digit_num = pow(10, digit - 1) * 9 * digit;
            accu += digit_num; 
            digit++;
        }
        n = n - accu;
        int n_num;
        n_num = (n-1) / digit + pow(10, digit-1);
        int n_pos = digit - (n-1)%digit;
        int j = pow(10, n_pos-1);

        
        // int n_pos = n % digit;
        // if(n_pos == 0) return n_num%10;
        // n_pos = digit - n_pos;
        // int i = pow(10, n_pos+1);
        // int j = pow(10, n_pos);
        return (n_num%(10*j))/j;
    }
};

class Solution {
public:
    int findNthDigit(int n) {
        int len = 1, start = 1;
        long count = 9;
        while (n > len * count) {
            n -= len * count;
            start *= 10;
            count *= 10;
            len++;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n - 1) % len] - '0';
    }
};

class Solution {
public:
    int findNthDigit(int n) {
        // step 1. calculate how many digits the number has.
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // step 2. calculate what the number is.
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;;

        // step 3. find out which digit in the number is we wanted.
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};

