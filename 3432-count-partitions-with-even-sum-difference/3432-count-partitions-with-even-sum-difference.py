class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        s = sum(nums)
        if s % 2 == 1:
            return 0
        return len(nums) - 1