// My solution 25ms
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        bool flag = false;
        for(int i = 0; i < arrays.size(); ++i){
            bool flg1 = false, flg2 = false;
            if(arrays[i].size() > 1) {
                if(arrays[i][0] < min1) {
                    min2 = min1;
                    min1 = arrays[i][0];
                    flg1 = true;
                } else if(arrays[i][0] < min2) {
                    min2 = arrays[i][0];
                }
                if(arrays[i][arrays[i].size()-1] > max1) {
                    max2 = max1;
                    max1 = arrays[i][arrays[i].size()-1];
                    flg2 = true;
                } else if (arrays[i][arrays[i].size()-1] > max2) {
                    max2 = arrays[i][arrays[i].size()-1];
                }
                if(flg1 && flg2) flag = true;
                else if(flg1 ^ flg2) flag = false;
            } else if (arrays[i].size() == 1) {
                bool flg3 = false;
                if(arrays[i][0] < min1) {
                    min2 = min1;
                    min1 = arrays[i][0];
                    flg3 = true;
                } else if(arrays[i][0] < min2) {
                    min2 = arrays[i][0];
                }
                if(arrays[i][0] > max1) {
                    max2 = max1;
                    max1 = arrays[i][0];
                    flg3 = true;
                } else if(arrays[i][0] > max2) {
                    max2 = arrays[i][0];
                }
                if(flg3) flag = false;
            } 
        }
        if(flag) {
            return max(abs(max1-min2), abs(max2-min1));
        } else return abs(max1-min1);
    }
};



// 22ms
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = INF;
        int maxi = -INF;
        
        int ans = 0;
        for (const auto& array: arrays) {
            int a = *array.begin();
            int b = *array.rbegin();
            
            if (mini != INF) {
                ans = max(ans, abs(b - mini));
                ans = max(ans, abs(maxi - a));
            }
            mini = min(mini, a);
            maxi = max(maxi, b);
        }
        return ans;
    }
};
