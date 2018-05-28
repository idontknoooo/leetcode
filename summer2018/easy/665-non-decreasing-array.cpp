// My solution 46ms
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        bool tf1 = false, tf2 = false;
        for(int i = 0; i < nums.size()-1; ++i){
            if(nums[i]>nums[i+1]) {
                ++count;
                tf1 = false, tf2 = false;
                if(i-1>=0 && i<nums.size() && nums[i-1] > nums[i+1]) tf1 = true;
                if(i+2 < nums.size() && nums[i] > nums[i+2]) tf2 = true;
                if(tf1 && tf2) return false;
                if(count > 1) return false;
            }
        }
        return true;
    }
};
// 35 ms 
/*
This problem is like a greedy problem. 
When you find nums[i-1] > nums[i] for some i, you will prefer to change nums[i-1]'s value, since a larger nums[i] will give you more risks that you get inversion errors after position i. 

But, if you also find nums[i-2] > nums[i], then you have to change nums[i]'s value instead, or else you need to change both of nums[i-2]'s and nums[i-1]'s values.
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;                                             //the number of changes
        
//        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] > nums[i]) {
                cnt++;
                
                if(cnt>1) return false;
                
                if(i-2<0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];                        //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                       //have to modify nums[i]
            }
        }

        return true;
    } 
};


/*
"NON-DECREASING" is a double negative. This is the same as an array sorted in ascending order where nums[i-1] <= nums[i].

Find the first exception to this rule where nums[i-1] > nums[i],
then see if the rest of the array is sorted in ascending order ( without nums[i-1] ) XOR ( without nums[i] ).

*/
/*
class Solution {
public:
    bool checkPossibility(const vector<int>& num) {
        vector<int> nums(num);  // create a new vector, not to modifty the original data.
        
        for (int i=1; i < nums.size(); i++){
            if (nums[i-1]<=nums[i]) 
                continue;
            
            int temp = nums[i-1];
            
            nums[i-1] = nums[i];
            if (is_sorted(nums.begin(),nums.end())) 
                return true;
            
            nums[i-1] = nums[i] = temp;
            return is_sorted(nums.begin(),nums.end());
        }
        
        return true;
    }
};
*/


