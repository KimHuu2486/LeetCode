class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for k in range(n):
            res = (res + math.comb(n-1, k) * nums[k]) % 10
        return res
