class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        INT_MAX = 10**9
        dp = [INT_MAX] * (n + 1)
        dp[0] = 0

        for i in range(n):
            dp[i + 1] = min(dp[i + 1], dp[i] + costs[i] + 1)
            if i + 2 <= n:    
                dp[i + 2] = min(dp[i + 2], dp[i] + costs[i + 1] + 4)
            if i + 3 <= n:
                dp[i + 3] = min(dp[i + 3], dp[i] + costs[i + 2] + 9)
        
        return dp[n]