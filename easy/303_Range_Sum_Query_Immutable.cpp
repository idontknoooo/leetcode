// class NumArray {
// public:
//     NumArray(vector<int> nums) : psum(nums.size()+1, 0) {
//         partial_sum( nums.begin(), nums.end(), psum.begin()+1);
//     }

//     int sumRange(int i, int j) {
//         return psum[j+1] - psum[i];
//     }
// private:
//     vector<int> psum;    
// };
// class NumArray {
// public:
//     NumArray(vector<int> nums) {
//         accu.push_back(0);
//         for (int num : nums)
//             accu.push_back(accu.back() + num);
//     }

//     int sumRange(int i, int j) {
//         return accu[j + 1] - accu[i];
//     }
// private:
//     vector<int> accu;
// };
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> nums) {
        if (nums.empty()) return;
        sums.resize(nums.size()+1, 0);
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        
    }
    
    int sumRange(int i, int j) {
        if (sums.empty()) return 0;
        return sums[j] - (i>0 ? sums[i-1] : 0);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */