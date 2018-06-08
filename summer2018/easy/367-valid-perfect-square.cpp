// Math
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};


// Binary search
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0 || num==1) return true;
        int l = 0, r = num / 2, m = l + (r-l) / 2;
        while(l + 1 < r) {
            if(m == 1.0*num/m) return true;
            else if(m < num/m) l = m;
            else r = m;
            m = l + (r-l) / 2;
        }
        if(l == 1.0*num/l) return true;
        if(r == 1.0*num/r) return true;
        return false;
    }
};
