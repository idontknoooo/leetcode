class Solution {
public:
    bool isUgly(int num) {
        // if(num==1) return true;
        // if(num==0) return false;
        // unordered_set<int> us = {2,3,5};
        // int tf = true;
        // while(tf)
        // {
        //     if(num%2==0)
        //         num/=2;
        //     else if(num%3==0)
        //         num/=3;
        //     else if(num%5==0)
        //         num/=5;
        //     else
        //         tf = false;
        // }
        // if(us.find(num)==us.end() && num!=1)
        //     return false;
        // return true;
        for (int i=2; i<6 && num; i++)
        while (num % i == 0)
            num /= i;
        return num == 1;
    }
};
