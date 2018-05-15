class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int cur_max = 0, cur_min = prices[0], result = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(cur_max > prices[i]){
                result += cur_max - cur_min;
                cur_min = prices[i];
            } 
            cur_max = prices[i];
        }
        result += cur_max - cur_min;
        return result;
    }
};
