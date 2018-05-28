// My solution 10ms
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(!c) return true;
        for(int i = 1; i <= sqrt(c); ++i){
            int num = floor(sqrt(c - i*i));
            if(num * num + i * i == c) return true;
        }
        return false;
    }
};


// 4ms
class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = 0, e = (int)sqrt(c);
        while(b <= e) {
            long sum = b * b + e * e;
            if (sum == c) {
                return true;
            } else if (sum >= c) {
                e--;
            } else {
                b++;
            }
        }
        return false;
    }
};
