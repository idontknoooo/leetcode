// 6ms
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size=nums.size();
        if(size==0||nums.empty())
        {
            return 0;
        }
        vector<int> f(size,0),g(size,0);
        int res=nums[0];
        f[0]=nums[0];
        g[0]=nums[0];
        for(int i=1;i<size;++i)
        {
            f[i]=max(nums[i],max(nums[i]*f[i-1],nums[i]*g[i-1]));
            g[i]=min(nums[i],min(nums[i]*g[i-1],nums[i]*f[i-1]));
            res=max(res,f[i]);
        }
        return res;
    }
};

// 5ms
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n = A.size();
        int frontProduct = 1;
      int backProduct = 1;
      int ans = INT_MIN;
      for (int i = 0; i < n; ++i) {
        frontProduct *= A[i];
        backProduct *= A[n - i - 1];
        ans = max(ans,max(frontProduct,backProduct));
          frontProduct = frontProduct == 0 ? 1 : frontProduct;
          backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};
