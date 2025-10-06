class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        heap = [(grid[0][0], 0, 0)];
        visited = [[False]*n for _ in range (n)]
        dirs = [[1, 0], [-1,0],[0, 1], [0, -1]]
        while heap:
            height, x, y = heapq.heappop(heap)
            if visited[x][y]:
                continue
            visited[x][y] = True
            if x == n-1 and y == n-1:
                return height
            for i in range (4):
                newX = x + dirs[i][0]
                newY = y + dirs[i][1]
                if newX < 0 or newX >= n or newY <0 or newY >= n or visited[newX][newY]:
                    continue
                heapq.heappush(heap, (max(height, grid[newX][newY]), newX, newY))
        return 0;