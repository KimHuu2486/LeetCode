class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        inc, des = True, True
        p = 0

        for i in range(n):
            if nums[i] == 0:
                p = i

            nxt = nums[(i + 1) % n]

            if nxt != (nums[i] + 1) % n:
                inc = False
            
            if nxt != (nums[i] - 1 + n) % n:
                des = False
        
        ans = 1e9

        if inc:
            ans = min(ans, min(p, n - p + 2))

        if des:
            ans = min(ans, min(n - p, p + 2))

        if ans == 1e9:
            return -1
        return ans