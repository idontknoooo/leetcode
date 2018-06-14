// Recursive
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > result;
      permuteRecursive(num, 0, result);
      return result;
    }
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)  {
      if (begin==num.size()-1) {
          result.push_back(num);
          return;
      }
      for (int i = begin; i < num.size(); i++) {
          swap(num[begin], num[i]);
          permuteRecursive(num, begin + 1, result);
          swap(num[begin], num[i]);
      }
    }
};

// Non-recursive
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int amount=1;
        vector<vector<int> >res;
        for(int i=2;i<=(int)nums.size();i++)amount*=i;//计算不同排列的数量，为n！
        for(int i=0;i<amount;i++,nextPermutation(nums))res.push_back(nums);//生成n！种不同的排列方式
        return res;
    }
    void nextPermutation(vector<int>& nums) {
        for(int i=(int)nums.size()-2;i>=0;i--){//从数组末尾寻找逆序相邻数对
            if(nums[i]<nums[i+1]){
                for(int j=(int)nums.size()-1;j>i;j--){//从后往前找到第一个比num[i]大的数，交换两者位置，并对i+1~end 进行reverse
                    if(nums[j]>nums[i]){
                        swap(nums[i],nums[j]);
                        reverse(nums.begin()+i+1, nums.end());
                        return;
                    }
                }
            }
        }//特殊情况，数组已经从大到小排列好，这时只需要reverse数组，即可
        reverse(nums.begin(), nums.end());
        return;
    }
};
