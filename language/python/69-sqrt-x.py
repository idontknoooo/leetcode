class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        ans = x / 2.0
        while abs(ans*ans - x) > 0.00001:
            ans = ans - (ans*ans - x) / (2.0*ans)
        return int(ans)
        
