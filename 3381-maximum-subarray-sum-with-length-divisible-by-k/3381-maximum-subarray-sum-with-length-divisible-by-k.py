class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        pref = [0] * (n + 1)
        bestMin = [1 << 62] * k
        bestMin[0] = 0

        for i in range (0, n):
            pref[i + 1] = pref[i] + nums[i]

        ans = -(1 << 62)
        for b in range (1, n + 1):
            r = b % k

            if bestMin[r] != (1 << 62):
                ans = max(ans, pref[b] - bestMin[r])
            
            bestMin[r] = min(bestMin[r], pref[b])

        return ans