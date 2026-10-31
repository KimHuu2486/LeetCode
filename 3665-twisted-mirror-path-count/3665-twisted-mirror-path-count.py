class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[[0, 0] for _ in range(n)] for _ in range(m)]
        dp[1][0][1] = 1
        dp[0][1][0] = 1
        MOD = 10**9 + 7

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                
                right, down = dp[i][j]

                if grid[i][j] == 1:
                    right, down = down, right
                else:
                    right = down = (right + down) % MOD
            
                if j + 1 < n:
                    dp[i][j + 1][0] = (dp[i][j + 1][0] + right) % MOD
                
                if i + 1 < m:
                    dp[i + 1][j][1] = (dp[i + 1][j][1] + down) % MOD

        return sum(dp[m - 1][n - 1]) % MOD 