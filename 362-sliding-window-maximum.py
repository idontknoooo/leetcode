import collections
class Solution:
    """
    @param nums: A list of integers.
    @param k: An integer
    @return: The maximum number inside the window at each moving.
    """
    def maxSlidingWindow(self, nums, k):
        # write your code here
        if not nums or not k: return []
        
        dq = collections.deque([])
        
        for i in range(k-1):
            self.add(nums, i, dq)
        ans = []    
        n = len(nums)
        for i in range(k-1, n):
            self.add(nums, i, dq)
            print(dq)
            print([nums[i] for i in list(dq)])
            ans.append(nums[dq[0]])
            if i-k+1 == dq[0]:
                dq.popleft()
                
        return ans        
        
    def add(self, nums, i, dq):
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()
        dq.append(i) 

#arr = [1,2,3,1,2,2]
arr = [1397,576,1256,334,233,1309,575,48,1308,1524,1776,1514,541,1027,43,1073,1136,83,1376,104,864,1578,57]
k = 8
solution = Solution()
print(solution.maxSlidingWindow(arr, k))
