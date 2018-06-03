// O(n) solution
/*
  Starting from most right,
  If right > left, this will be the max area for left node. Thus, move left to left + 1
  If right < left, then this is the max area for right node. Thus, move right to right - 1
  In this way, we can always compare current result with max values
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, i = 0, j = height.size() - 1;
        while(i < j) {
            if(height[j] > height[i]) {
                ans = max(ans, height[i] * (j-i++));
            } else {
                ans = max(ans, height[j] * (j---i));
            }
        }
        return ans;
    }
};

// O(n^2) solution, this will fail to pass time limit, but it's the most basic solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i = 0; i < height.size(); ++i) 
            for(int j = i + 1; j < height.size(); ++j) 
                ans = max(ans, min(height[i], height[j]) * (j-i));
        return ans;
    }
};

