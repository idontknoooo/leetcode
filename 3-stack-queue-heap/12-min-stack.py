class MinStack:
    
    def __init__(self):
        # do intialization if necessary
        self.stack = []
        self.min_stack = []

    """
    @param: number: An integer
    @return: nothing
    """
    def push(self, number):
        # write your code here
        self.stack.append(number)
        if not self.min_stack or number <= self.min_stack[-1]:
            self.min_stack.append(number)

    """
    @return: An integer
    """
    def pop(self):
        # write your code here
        val = self.stack.pop()
        if self.min_stack and val <= self.min_stack[-1]:
            self.min_stack.pop()
        return val

    """
    @return: An integer
    """
    def min(self):
        # write your code here
        return self.min_stack[-1]

