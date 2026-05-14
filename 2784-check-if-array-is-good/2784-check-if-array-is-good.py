class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums)
        freq = [0] * n
        for i in range(n):
            if nums[i] >= n or nums[i] <= 0:
                return False
            freq[nums[i]]+=1
            if freq[nums[i]] >= 3:
                return False
            elif freq[nums[i]] >= 2 and nums[i] != n - 1:
                return False
        return True
            