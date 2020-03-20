class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        # O(n) time
        # we scan from left to right, "total" tracks the 
        # sum of the subarray. If the sum is less than s,
        # right moves forward one step, else left moves forward
        # one step, left and right form a window.
        left, right = -1, 0
        total = 0
        res = len(nums) + 1
        while right < len(nums):
            total += nums[right]
            while total >= s:
                res = min(res, right-left+1)
                total -= nums[left]
                left += 1
            right += 1
        return res if res <= len(nums) else 0
