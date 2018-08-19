# translated from cpp, not the best solution
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        elif n == 2:
            return 2
        first, second = 1, 2
        while n > 2:
            tmp = second 
            second += first
            first = tmp
            n -= 1
        return second

# Pythonic solution
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        a = 0
        b = 1
        for _ in range(n):
            a, b = b, a + b
        return b
        
