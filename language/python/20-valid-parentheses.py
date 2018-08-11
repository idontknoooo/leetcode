# My method
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left = "({["
        pair = {')':'(', ']':'[', '}':'{'}
        stack = [] 
        for c in s:
            if c in left:
                stack.insert(0, c)
            else:    
                if stack and pair[c] == stack[0]:
                    stack.pop(0)
                else:
                    return False 
        return not stack
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pair = {')':'(', ']':'[', '}':'{'}
        stack = [] 
        for c in s:
            if c in pair.values():
                stack.append(c)
            else:    
                if stack and pair[c] == stack[-1]:
                    stack.pop()
                else:
                    return False 
        return not stack
# Better method
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        amap = {
            "(": ")",
            "{": "}",
            "[": "]"
        }
        stack = []
        for c in s:
            if c in amap:
                stack.append(amap[c])
            else:
                if not stack:
                    return False
                val = stack.pop()
                if c != val:
                    return False
        return len(stack) == 0
