class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        diff = [0] * (limit * 2 + 2)

        for i in range(n // 2):
            a = min(nums[i], nums[n - 1 - i])
            b = max(nums[i], nums[n - 1 - i])

            diff[2] += 2
            diff[2 * limit + 1] -= 2

            diff[a + 1] -= 1
            diff[limit + b + 1] += 1

            diff[a + b] -= 1
            diff[a + b + 1] += 1
        
        ans = n
        cur = 0

        for i in range(2, 2 * limit + 1):
            cur += diff[i]
            ans = min(ans, cur)
        
        return ans