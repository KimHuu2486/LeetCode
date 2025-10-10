class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        dp = [-1] * n
        ans = float("-inf")
        for i in range(n - 1, -1, -1):
            if i + k < n:
                dp[i] = dp[i + k] + energy[i]
            else:
                dp[i] = energy[i]
            ans = max(ans, dp[i])
        return ans
