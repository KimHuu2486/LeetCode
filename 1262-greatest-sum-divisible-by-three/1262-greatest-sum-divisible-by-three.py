class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, -1e9, -1e9]
        for x in nums:
            old = dp[:]
            for i in range(3):
                ni = (x + i) % 3
                dp[ni] = max(x + old[i], dp[ni])
        return dp[0]