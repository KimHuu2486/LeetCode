class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * k
        dp = [0] * k

        for num in nums:
            newDp = [0] * k
            newDp[num % k] += 1

            for r in range(0, k):
                newDp[(r * num) % k] += dp[r]
            
            for r in range(0, k):
                ans[r] += newDp[r]
            
            dp = newDp
        
        return ans