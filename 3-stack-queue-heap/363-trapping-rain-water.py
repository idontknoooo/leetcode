# method 1
class Solution:
    """
    @param heights: a list of integers
    @return: a integer
    """
    def trapRainWater(self, heights):
        # write your code here
        ans = 0
        stack = []
        for i, h in enumerate(heights):
            while stack and h > heights[stack[-1]]:
                low = stack.pop()
                if stack:
                    left = stack[-1]
                    dis = i - left - 1 
                    bound = min(heights[left], heights[i]) - heights[low]
                    ans += dis * bound
            stack.append(i)
        return ans
                    
# method 2
class Solution:
    """
    @param heights: a list of integers
    @return: a integer
    """
    def trapRainWater(self, heights):
        if not heights: return 0
        left_max, right_max = heights[0], heights[-1]
        left, right = 0, len(heights) - 1
        ans = 0
        while left <= right:
            if left_max < right_max:
                if left_max < heights[left]:
                    left_max = heights[left]
                else:
                    ans += left_max - heights[left]
                left += 1
            else:
                if right_max < heights[right]:
                    right_max = heights[right]
                else:
                    ans += right_max - heights[right]
                right -= 1
        return ans
