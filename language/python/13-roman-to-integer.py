# From right to left
# if right < left, add 
# if left  > right, minus
class Solution(object):
    
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        sybl = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        res = 0
        pre = 1
        for letter in s[::-1]:
            if sybl[letter] >= pre: 
                res += sybl[letter]
            else:
                res -= sybl[letter]
            pre = sybl[letter]
        return res
