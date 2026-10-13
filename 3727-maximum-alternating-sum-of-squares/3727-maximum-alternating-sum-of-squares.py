class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)

        nums.sort(key = lambda x: abs(x))

        left, right, ans = 0, n - 1, 0

        while left < right:
            ans += nums[right]**2 - nums[left]**2

            left += 1
            right -= 1

        if left == right:
            ans += nums[right]**2

        return ans
