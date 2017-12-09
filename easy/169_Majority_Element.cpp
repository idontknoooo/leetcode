class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums.size()/2;
        vector<int> tmp;
        int i = 0;
        while(i < nums.size())
        {
            if(find(tmp.begin(), tmp.end(), nums[i])==tmp.end())
            {
                if(count(nums.begin(), nums.end(), nums[i])>maj)
                    return nums[i];
                else
                    tmp.push_back(nums[i]);
            }
            ++i;
        }
        cout << i << endl;
        return nums[i];
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0, numMajor = 0, n = nums.size();
        /********** Using HashMap
        // Runtime = 26ms
        
        unordered_map<int, int> map;
        
        for(int i = 0; i < n; i++)  {
            map[nums[i]] += 1;
            if(map[nums[i]] > count) {
                numMajor = nums[i];
                count = map[nums[i]];
            }
        }
        
        
 
        /***************************************************/
        
        /**************** Using sorting
        // Runtime = 22ms
        
        sort(nums.begin(), nums.end());
        int currEl = 0, currCount = 0; 
        for(int i = 0; i < n; i++)  {
            if(nums[i] != currEl) {
                currEl = nums[i];
                currCount = 1;
            }
            else    {
                currCount++;                
                }
            if(count < currCount)   {
                    numMajor = nums[i];
                    count = currCount;
            }
        }
        
        **************************************************/
        
        /*************** Moore Voting Algorithm
        // This algorithm runs in O(n) time and O(1) space.
        // Moore Voting Algo can only be used if the number of repetitons of a number is high i.e. is the majority eg: greater than n/2.
        // This algorithm will return a value even if there is no majority and that ret Val will be arr[0]. 
        // If it is not sure that the input array has a majority, a second pass can be made to check if the value obtained is a majority or not. */
        
        // In this algo if count = 0, we make the current ele as the major ele. else if the curr number is same as major, we increment the counter else decrement.
        
        // Runtime = 16ms.
        for(int i = 0; i < n; i ++) {
            if(count == 0)  {
                numMajor = nums[i];
            }
            if(numMajor == nums[i])
                count++;
            else
                count--;
        }
       /**************************************************/
        return numMajor;
    }
};