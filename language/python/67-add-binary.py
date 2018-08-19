class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        carry, m, n = 0, len(a)-1, len(b)-1
        ans = ""
        while m >= 0 or n >= 0 or carry:
            cur = carry
            if m >= 0:
                cur += int(a[m]) 
            if n >= 0:
                cur += int(b[n]) 
            carry = 1 if cur > 1 else 0    
            ans = "0" + ans if cur == 2 or cur == 0 else "1" + ans
            m, n = m-1, n-1    
        return "1" + ans if carry else ans
# Cheat
class Solution:
    def addBinary(self, a, b):
	# Convert to bianry
        a = int(a, 2)
        b = int(b,2)
	# Binary addition
	# {0:b} meaning first number is binary instead of print decimal
        return str("{0:b}".format((a+b)))
