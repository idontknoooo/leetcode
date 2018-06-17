// 5ms
class Solution {
public:
    vector<int> grayCode(int n) {        
        vector<int> res;
        if(n==0) {
            res.emplace_back(0);
            return res;
        }
        res = grayCode(n-1);
        auto a = 1<<(n-1);
        vector<int> resNew(res);
        for(auto i = res.rbegin() ; i!= res.rend(); ++i) {
            auto  x = (*i|a ); 
            resNew.emplace_back(x);
        }
        return resNew;
    }
};


// 4ms 主要还是找规律，或者说有规律的改变
/*
0 | 1 | 0 0 1 
1 | 3 | 0 1 1 
0 | 2 | 0 1 0 
2 | 6 | 1 1 0 
0 | 7 | 1 1 1 
1 | 5 | 1 0 1 
0 | 4 | 1 0 0 
1. 从最右侧开始，改变bit，每次向左移一位。
000
001
011
2. 如果不是最右位，则从最右开始改变bit，一直到当前位。
 ! -> 不是最右
011
  !-> 从最右开始改变一直到当前位
010

*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if(n == 0) return result; // when n == 0, return 0
        helper(n - 1, result);    // n-1
        return result;
    }
    
    void helper(int end, vector<int>& result) {
        if(end < 0) return; // When position less than 0, ends.
        for(int i = 0; i <= end; i++) {
            // toggle bit based on previous and push
            result.push_back(result.back() ^ (1 << i)); 
            helper(i - 1, result);
        }
    }
};
