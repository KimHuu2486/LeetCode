class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = [0] * n
        suffix = [0] * n
        for i in range (1, n):
            prefix[i] += prefix[i-1] + nums[i - 1]
        for i in range (n-2, -1, -1):
            suffix[i] += suffix[i + 1] + nums[i + 1]
        cnt = 0
        for i in range (0, n):
            if nums[i] == 0:
                if prefix[i] == suffix[i]:
                    cnt+=2
                elif abs(prefix[i] - suffix[i]) == 1:
                    cnt+=1
        return cnt