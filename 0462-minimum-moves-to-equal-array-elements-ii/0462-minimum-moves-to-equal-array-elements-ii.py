class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)
        mid = n//2
        med = nums[mid]

        if  n % 2 == 0:
            med = (nums[mid - 1] + nums[mid]) // 2
        
        ans = 0
        for num in nums:
            ans += abs(num - med)
        
        return ans