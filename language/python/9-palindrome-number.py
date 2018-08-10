# My method (152ms)
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        tmp = x
        num = 0
        while x > 0:
            num = num * 10 + x % 10
            x /= 10
        return num == tmp
# Other method (fastest 136ms) 
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        string = ""
        string += str(x)

        if string == string[::-1]:
            return True
        else:
            return False
# Super short code
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        return str(x)[::-1] == str(x)
