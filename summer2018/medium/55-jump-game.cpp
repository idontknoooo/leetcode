class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach =  0;
        for (int i = 0; i < nums.size(); i++){
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for(int i = 0; i < nums.size(); i++) {
            max_jump = max(max_jump, i + nums[i]);
            if(max_jump >= nums.size() - 1) return true;
            else if(max_jump == i) return false;
        }
        return false;
    }
};
