class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        cntOnes = nums.count(1)

        if (cntOnes > 0):
            return n - cntOnes

        best = float('inf')

        for i in range (n):
            g = nums[i]
            for j in range (i + 1, n):
                g = gcd(g, nums[j])
                if g == 1:
                    best = min(best, j - i + 1)
                    break

        if best != float('inf'):
            return (n - 1) + (best - 1)
        return -1