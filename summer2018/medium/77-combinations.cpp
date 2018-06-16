/* My thought. 
    Following iterative method use the relationship between each pair. I found out the pattern but forget to transfer this relation between each individual pair. Observe the pattern is important, but convert overall pattern to each process is also important.
*/
// 77ms 
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    int i = 0;
    vector<int> p(k, 0);
    while (i >= 0) { // when [n,n] has been filled, i will down to negative then quit
      p[i]++;
      if (p[i] > n) --i; // cannot change order of if statements
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
/* Output order
12
13
14
23
23
34
*/
public:
    vector<vector<int> > ans;
    // Use copy by reference, it's much faster if you don't make a copy
    void helper(vector<int>& tmp, int n, int k, int pos, int val) {
        if(k==0) ans.push_back(tmp);
        else {
            for(int i = val; i <= n; ++i) {
                tmp[pos] = i; // At current position, make different starting value
                helper(tmp, n, k-1, pos+1, i+1); // Adjust position and value
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp(k, 0);
        helper(tmp, n, k, 0, 1);
        return ans;
    }
};
