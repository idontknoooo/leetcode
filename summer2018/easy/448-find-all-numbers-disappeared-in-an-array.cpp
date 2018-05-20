// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         bitset<100000> bsq;
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             int idx = nums[i];
//             bsq.set(idx);
//         }
//         vector<int> res;
//         for(int i = 1; i <= nums.size(); ++i)
//             if(!bsq.test(i))
//                 res.emplace_back(i);
//         return res;
//     }
// };


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Similar to the question of duplicate integers from 1-n in array.
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int ndx = abs(nums[i]) - 1;
            nums[ndx] = (nums[ndx] > 0) ? -nums[ndx] : nums[ndx];
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
