class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_pos = 0, max_profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            max_profit = prices[i]-prices[min_pos] > max_profit? prices[i]-prices[min_pos] : max_profit;
            min_pos = prices[i] < prices[min_pos]? i : min_pos;
        }
        return max_profit;
    }
};
