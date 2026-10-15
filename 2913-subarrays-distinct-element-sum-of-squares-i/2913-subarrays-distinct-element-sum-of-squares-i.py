class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        ans = n
        for i in range(n - 1):
            s = set(nums[i: i + 1])
            for j in range(i + 1, n):
                s.add(nums[j])
                ans += len(s) ** 2

        return ans