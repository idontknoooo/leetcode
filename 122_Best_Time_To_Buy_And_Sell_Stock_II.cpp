class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (size_t p = 1; p < prices.size(); ++p) 
          ret += max(prices[p] - prices[p-1], 0);    
        return ret;
    }
};

// Suppose the first sequence is "a <= b <= c <= d", the profit is "d-a = (b-a) + (c-b) + (d-c)"
// Thus (b-a)+(d-c) <= d-a
