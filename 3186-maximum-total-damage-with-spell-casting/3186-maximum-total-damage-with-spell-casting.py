class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        freq = Counter(power) #like unordered_map in C++
        value = sorted(freq.keys())
        n = len(value)
        dp = [0] * n
        dp[0] = value[0] * freq[value[0]]
        for i in range(n):
            take = value[i] * freq[value[i]]
            prev = bisect.bisect_right(value, value[i] - 3) - 1   #like upper_bound in C++
            if prev >= 0:
                take += dp[prev]
            dp[i] = max(take, dp[i - 1])
        return dp[n - 1]
