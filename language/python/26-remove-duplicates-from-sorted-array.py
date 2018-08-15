class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        j = 1
        first = nums[0]
        last = nums[-1]
        while first != last:
            if nums[j] > first:
                first = nums[j]
                j += 1
            else:
                nums.pop(j)
        return j
