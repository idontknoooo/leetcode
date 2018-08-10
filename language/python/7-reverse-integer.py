# My solution, same speed but more lines of code
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1
        if x < 0:
            flag = 0
            x = -x
        res = 0
        while x > 0:
            res = x % 10 + res * 10
            x /= 10
        res = res if flag else -res    
        if res < -2**31 or res > 2**31-1:
            return 0
        else:
            return res
# Other's solution
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 1 if x > 0 else -1
        absx = abs(x)
        ret = 0
        while absx:
            absx, mod = divmod(absx, 10)
            if 10 * ret > 2 ** 31 - 1:
                return 0
            else:
                ret = 10 * ret + mod
        
        return ret * sign 
