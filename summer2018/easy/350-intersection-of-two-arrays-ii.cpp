class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        res.reserve(nums1.size());
        unordered_map<int,int> map;
        if(nums1.empty()||nums2.empty())
            return res;
        for(int m:nums1)
            map[m]++;
        for(int m:nums2)
        {
            if(map[m]!=0){
                res.push_back(m);
                map[m]--;
            }
        }
        return res;      
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        v1.erase(set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v1.begin()), v1.end());
        
        return v1;
    }
};
