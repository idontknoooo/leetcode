# Union find
# Knowledge Point:
#   question analysis
#       min-spanning-tree has only n-1 edges
#   sort object
#   operator.attrgetter
#   Union find with token number (n)
#       city doesn't have a 'id', we assign a token number (n) to it 
'''
Definition for a Connection
class Connection:

    def __init__(self, city1, city2, cost):
        self.city1, self.city2, self.cost = city1, city2, cost
'''
from operator import attrgetter
class Solution:
    # @param {Connection[]} connections given a list of connections
    # include two cities and cost
    # @return {Connection[]} a list of connections from results
    def lowestCost(self, connections):
        # Write your code here

        connections = sorted(connections, key=attrgetter('cost', 'city1', 'city2'))

        n = 0
        mapping = {}
        for conn in connections:
            if conn.city1 not in mapping:
                mapping[conn.city1] = n
                n += 1
            if conn.city2 not in mapping:
                mapping[conn.city2] = n
                n += 1

        result = []
        self.p = [i for i in range(n)]
        for conn in connections:
            num1, num2 = mapping[conn.city1], mapping[conn.city2]
            par1, par2 = self.find(num1), self.find(num2)
            if par1 != par2:
                self.p[par1] = par2
                result.append(conn)

        return result if len(result) == n - 1 else []

    def find(self, n):
        if self.p[n] != n:
            self.p[n] = self.find(self.p[n])
        return self.p[n]

