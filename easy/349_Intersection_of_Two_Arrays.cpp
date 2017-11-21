// class Solution {
// public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     set<int> s(nums1.begin(), nums1.end());
//     vector<int> out;
//     for (int x : nums2)
//         if (s.erase(x))
//             out.push_back(x);
//     return out;
// }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};