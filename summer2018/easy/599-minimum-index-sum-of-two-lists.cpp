// My solution 103ms beat 63%
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> um;
        for(int i = 0; i < list1.size(); ++i){
            um[list1[i]] = i;
        }
        unordered_map<string, int> um1;
        for(int i = 0; i < list2.size(); ++i){
            um1[list2[i]] = i;
        }
        int min_dis = INT_MAX;
        unordered_map<int, vector<string> > um2;
        for(int i = 0; i < list1.size(); ++i){
            if(um1.find(list1[i]) != um1.end() && um.find(list1[i]) != um.end() && min_dis >= um1[list1[i]] + um[list1[i]]){
                min_dis = um1[list1[i]] + um[list1[i]];
                um2[min_dis].push_back(list1[i]);
            }
        }
        return um2[min_dis];
    }
};
