class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        s = sum(nums)
        r = s % k
        cnt = 0
        idx = 0
        while r:
            dif = min(r, nums[idx])
            r -= dif
            cnt += dif
            idx += 1
        return cnt 