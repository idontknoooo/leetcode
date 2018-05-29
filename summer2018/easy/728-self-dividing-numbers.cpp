// My solution beat 100%
class Solution {
public:
    bool selfDiv(int num){
        if(!num) return false;
        int copy = num;
        while(num > 0){
            int tmp = num % 10;
            if(!tmp || copy%tmp) return false;
            num /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> vec;
        for(int i = left; i <= right; ++i){
            if(selfDiv(i)) vec.push_back(i);
        }
        return vec;
    }
};
