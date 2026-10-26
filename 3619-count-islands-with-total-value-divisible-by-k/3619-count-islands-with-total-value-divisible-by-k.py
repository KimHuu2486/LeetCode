class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(i, j):
            if not (0 <= i < m and 0 <= j < n):
                return 0 
            if grid[i][j] == 0:
                return 0  
            
            val = grid[i][j]
            grid[i][j] = 0 

            return val + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1) 

        return sum(dfs(i, j) % k == 0 for i, j in product(range(m), range(n)) if grid[i][j])