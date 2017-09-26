class Solution {
public:
    string convertToTitle(int n) {
        string re = "";
        int tmp = 0;
        while(n>0)
        {
            tmp = n % 26;
            re = (tmp? char(tmp+64) : 'Z') + re;
            n = (tmp? n/26 : n/26-1);
        }
        return re;
    }
};

return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');
