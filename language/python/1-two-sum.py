# My method
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_dict = {}
        i = 0
        for num in nums:
            if target - num in hash_dict:
                return [hash_dict[target - num], i]
            else:
                hash_dict[num] = i
            i += 1    
        return []                

# Other method - much quicker 
class Solution(object):
    def findSecondIndex(self, nums, secondNum):
        for secondIndex, num in enumerate(nums):
            if secondNum == num:
                return secondIndex
    def twoSum(self, nums, target):
        numsSet = set(nums)
        for firstIndex, num in enumerate(nums):
            secondNum = target - num
            if secondNum in numsSet:
                secondIndex = self.findSecondIndex(nums, secondNum)
                if firstIndex is not secondIndex:
                    return [firstIndex, secondIndex]
