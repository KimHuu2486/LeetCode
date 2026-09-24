class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        def sumDigit(x):
            ans = 0
            while x > 0:
                ans += x % 10
                x //= 10
            return ans
        
        n = len(nums)
        for i in range(n):
            if i == sumDigit(nums[i]):
                return i
        
        return -1