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
