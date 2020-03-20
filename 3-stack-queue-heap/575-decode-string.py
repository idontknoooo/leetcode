# method 1
class Solution:
    """
    @param s: an expression includes numbers, letters and brackets
    @return: a string
    """
    def expressionExpand(self, s):
        # write your code here
        stack = []; curNum = 0; curString = ''
        for c in s:
            if c == '[':
                stack.append(curString)
                stack.append(curNum)
                curString = ''
                curNum = 0
            elif c == ']':
                num = stack.pop()
                prevString = stack.pop()
                curString = prevString + num*curString
            elif c.isdigit():
                curNum = curNum*10 + int(c)
            else:
                curString += c
        return curString

# method 2
import collections
class Solution:
    """
    @param s: an expression includes numbers, letters and brackets
    @return: a string
    """
    def expressionExpand(self, s):
        stack = collections.deque()
        for c in s:
            if c == ']':
                tmp_str = collections.deque()
                while stack and stack[-1] != '[':
                    tmp_str.appendleft(stack.pop())
                stack.pop()
                tmp_num = collections.deque()
                while stack and stack[-1].isdigit():
                    tmp_num.appendleft(stack.pop())
                stack.append(int(''.join(tmp_num)) * ''.join(tmp_str))
            else:
                stack.append(c)
        return ''.join(stack)
