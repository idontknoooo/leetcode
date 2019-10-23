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
        # write your code here
        ans = 0
        stack = []
        for cur in range(len(heights)):
            while stack and heights[cur] > heights[stack[-1]]:
                right = stack.pop()
                if not stack:
                    break
                left = stack[-1]
                distance = cur - left - 1
                bounded_height = min(heights[cur], heights[left]) - heights[right]
                ans += distance * bounded_height
            stack.append(cur)
        return ans

