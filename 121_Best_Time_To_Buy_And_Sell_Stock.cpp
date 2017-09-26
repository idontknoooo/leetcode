// Brute Force: Exceed time limit
#include <algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, tmp = 0;
        if(prices.size()<2) return max;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices.begin()+i != prices.end())
                tmp = *max_element(prices.begin()+i,prices.end())-prices[i-1];
            if(tmp>max)
                max = tmp;
        }
        return max;
    }
};


// Better Option
int maxProfit(vector<int>& prices) {
	int maxPro = 0;
	int minPrice = INT_MAX;
	for(int i = 0; i < prices.size(); i++){
		minPrice = min(minPrice, prices[i]);
		maxPro = max(maxPro, prices[i] - minPrice);
	}
	return maxPro;
}
