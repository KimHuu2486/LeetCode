class Solution:
    def minMoves(self, nums: List[int]) -> int:
        maxEle = max(nums)
        ans = 0
        for num in nums:
            ans += maxEle - num
        return ans