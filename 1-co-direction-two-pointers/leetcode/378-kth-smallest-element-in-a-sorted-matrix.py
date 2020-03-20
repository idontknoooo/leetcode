# Heap
import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
            
        heap = [(matrix[0][0],0,0)]
        m, n = len(matrix), len(matrix[0])
        visited = set((0,0))
        res = None
        while k > 0:
            res = heapq.heappop(heap)
            r, c = res[1], res[2]
            if r+1 < m and (r+1,c) not in visited:
                heapq.heappush(heap, (matrix[r+1][c], r+1, c))
                visited.add((r+1,c))
            if c+1 < n and (r,c+1) not in visited:
                heapq.heappush(heap, (matrix[r][c+1], r, c+1))
                visited.add((r,c+1))
            k -= 1
        return res[0]


# Binary Search
from bisect import bisect_right

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        l,r = matrix[0][0], matrix[-1][-1]
        while l<r:
            mid = (l+r)//2
            s = sum([bisect_right(row, mid) for row in matrix])
            if s < k:
                l = mid + 1
            else:
                r = mid                
        return l
