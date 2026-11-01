class Solution:
    def minMoves(self, nums: list[int]) -> int:
        minEle = min(nums)
        ans = sum(num - minEle for num in nums)

        return ans
