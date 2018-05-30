class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> costlist;
        costlist.push_back(0);
        costlist.push_back(0);               
        for (int i = 2; i <= cost.size(); i ++)        
            costlist.push_back(min(costlist[i-1] + cost[i-1], costlist[i-2] + cost[i-2]));        
        return costlist[cost.size()];
        
    }
};


// O(1) space
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0, dp = 0;
        for(int i = 2; i <= cost.size(); ++i) {
            dp = min(a + cost[i-1], b + cost[i-2]);
            b = a;
            a = dp;
        }
        return a;
    }
};

