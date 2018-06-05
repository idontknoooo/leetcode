// 77ms 
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    int i = 0;
    vector<int> p(k, 0);
    while (i >= 0) {
      p[i]++;
      if (p[i] > n) --i;
      else if (i == k - 1) result.push_back(p);
      else {
          ++i;
          p[i] = p[i - 1];
      }
    }
    return result;
  }
};

//  67ms
class Solution {
public:
void myCombine(vector<vector<int>>& res, vector<int>& cur, int pos, int count, int k, int n) {
    if (k == 0) {
        res.push_back(cur);
        return;
    }
    for (int i = pos; i <= n; i++) {
        cur[count] = i;
        myCombine(res, cur, i + 1, count + 1, k - 1, n);
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur(k, 0);
    myCombine(res, cur, 1, 0, k, n);
    return res;
}
};
