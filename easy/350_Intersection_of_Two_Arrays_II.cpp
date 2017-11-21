class Solution {
public:
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> dict;
    //     vector<int> res;
    //     for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
    //     for(int i = 0; i < (int)nums2.size(); i++)
    //         if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
    //     return res;
    // }
    vector<int> intersect(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
    return a;
}
};