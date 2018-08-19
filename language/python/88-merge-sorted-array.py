# My way from c++ (in-place) (40ms)
class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        cur = m + n - 1
        m, n = m-1, n-1
        while m >= 0 and n >= 0 and cur >= 0:
            if nums1[m] > nums2[n]:
                nums1[cur] = nums1[m]
                m -= 1
            else:
                nums1[cur] = nums2[n]
                n -= 1
            cur -= 1    
        while n >= 0:
            nums1[cur] = nums2[n]
            n   -= 1
            cur -= 1
# Faster python (36ms)
class Solution:
    def merge(self, nums1, m, nums2, n):
        nums1[m:] = nums2
        nums1.sort()
