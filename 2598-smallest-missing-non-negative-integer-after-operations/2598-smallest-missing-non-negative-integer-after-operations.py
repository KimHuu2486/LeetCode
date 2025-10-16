class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        mp = [0] * value
        for x in nums:
            mp[x % value] += 1
        ans = 0
        while mp[ans % value] > 0:
            mp[ans % value] -= 1
            ans += 1
        return ans
