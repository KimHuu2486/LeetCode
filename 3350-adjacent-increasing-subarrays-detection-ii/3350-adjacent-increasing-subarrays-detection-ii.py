class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        i, j, prev, ans = 0, 1, 0, 0
        while j < len(nums):
            if nums[j] <= nums[j - 1]:
                ans = max(ans, (j - i) // 2, min(prev, j - i))
                prev = j - i
                i = j
            j += 1
        ans = max(ans, (j - i) // 2, min(prev, j - i))
        return ans
