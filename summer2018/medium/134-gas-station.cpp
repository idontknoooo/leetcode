// 8ms
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==0||cost.size()==0||gas.size()!=cost.size())
        {
            return -1;
        }
        int total=0;
        int sum=0;
        int start=0;
        for(int i=0;i<gas.size();++i)
        {
            total+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
            if(sum<0)
            {
                start=i+1;
                sum=0;
            }
        }
        return total<0?-1:start;
    }
};
