class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)

        prefix = [0] * n
        suffix = [0] * n
        ans = [0] * n

        prefix[0] = nums[0]
        for i in range(1, n):
            prefix[i] = max(prefix[i - 1], nums[i])
        
        suffix[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            suffix[i] = min(suffix[i + 1], nums[i])

        ans[n - 1] = prefix[n - 1]
        for i in range(n - 2, -1, -1):
            if prefix[i] > suffix[i + 1]:
                ans[i] = ans[i + 1]
            else:
                ans[i] = prefix[i]

        return ans
