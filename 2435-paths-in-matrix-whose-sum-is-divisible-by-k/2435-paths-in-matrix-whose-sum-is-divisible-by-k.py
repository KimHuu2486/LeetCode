class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        MOD = 10**9 + 7
        dp = [[0] * k for _ in range(n)]
        
        for i in range(m):
            new_dp = [[0] * k for _ in range(n)]

            for j in range(n):
                vals = grid[i][j] % k
                if i == 0 and j == 0:
                    new_dp[j][vals] = 1
                    continue

                for r in range(k):
                    ways = 0
                    if i > 0:
                        ways += dp[j][r]
                    if j > 0:
                        ways += new_dp[j - 1][r]
                    if ways == 0:
                        continue
                    nr = (vals + r) % k    
                    new_dp[j][nr] = (new_dp[j][nr] + ways) % MOD

            dp, new_dp = new_dp, dp
        
        return dp[n-1][0]