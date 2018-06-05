// 5ms
class Solution {
public:
    
    
    vector<int> grayCode(int n) {        
        
        vector<int> res;
        if(n==0)
        {
            res.emplace_back(0);
            return res;
        }
        
        res = grayCode(n-1);
        auto a = 1<<(n-1);
        vector<int> resNew(res);
        for(auto i = res.rbegin() ; i!= res.rend(); ++i)
        {
            auto  x = (*i|a ); 
            resNew.emplace_back(x);
        }
        
        return resNew;
        
    }
};


// 4ms


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if(n == 0) return result;   
        helper(n - 1, result);
        return result;
    }
    
    void helper(int end, vector<int>& result) {
        if(end < 0) return;
        
        for(int i = 0; i <= end; i++) {
            result.push_back(result.back() ^ (1 << i));
            helper(i - 1, result);
        }
    }
};




/*
0 0 0
0 0 1
0 1 1
0 1 0

1 1 0
1 1 1
1 0 1
1 0 0

flip start bits
flip start+1 bits
    flip start bits
flip start + 2

for i = 0 : n - 1
  for j = 0 to i - 1
    flip jth bit add the results
    
    

      

*/
//2:13


