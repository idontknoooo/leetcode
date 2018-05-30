// My solution 5ms beat 70%
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        int num = 0, digit = 0;
        bool flg1 = false;
        for(int i = 1; i <= N; ++i){
            num = i;
            flg1 = false;
            while(num > 0){
                digit = num % 10;
                if(digit == 2 || digit == 5 || digit == 6 || digit == 9) flg1 = true;
                else if(digit == 3 || digit == 4 || digit == 7) break;
                num /= 10;
            }
            if(num <= 0 && flg1) ++count;
        }
        return count;
    }
};
