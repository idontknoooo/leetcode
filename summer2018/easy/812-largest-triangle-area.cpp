// math question https://leetcode.com/problems/largest-triangle-area/discuss/122711/C++JavaPython-Solution-with-Explanation-and-Prove
// O(n^3)
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double res = 0;
        for (auto &i : p) // For each point
          for (auto &j : p) // For each point
            for (auto &k : p) // For each point
              res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return res;
    }
};
