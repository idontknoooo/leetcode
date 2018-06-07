class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size() / 2;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); ++i){
           if(!um[nums[i]]) {
               um[nums[i]] = 1;
           } else {
               um[nums[i]]++;
           }
           if(um[nums[i]]>size) return nums[i]; 
        }
    }
};

// Faster
// 求一个元素 出现次数超过n/2次的
// 最简单的方法就是排序 找出中间元素
// 排序时间复杂度为O(nlogn)
// 还有一种复杂度为O(n)的算法 是对数组进行遍历 每遍历一个数就进行计数 如果重复+1 如果不是重复的就-1 并替换成新的元素 最后剩下的元素就是出现
// 次数最多的元素
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int m = nums.size();
        int temp = nums[0], count = 1;
        for(int i=1;i<m;++i)
        {
            if(temp == nums[i])
                ++count;
            else
            {
                if(count == 0)
                {
                    temp = nums[i];
                    //count = 1;
                }
                else
                    --count;
            }
        }
        return temp;
    }
    
    /*
    int majorityElement(vector<int>& nums) 
    {
        int m = nums.size();
        sort(nums.begin(),nums.end());
        return nums[m/2];
    }
    */
};
