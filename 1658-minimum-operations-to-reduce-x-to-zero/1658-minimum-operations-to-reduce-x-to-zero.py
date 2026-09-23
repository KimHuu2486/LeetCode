class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        n = len(nums)
        pref = [0] * (n + 1)
        firstIdx = {}
        maxLen = -1

        for i in range(0, n):
            pref[i + 1] = pref[i] + nums[i]

        sumTar = pref[n] - x
        if sumTar == 0:
            return n

        for i, val in enumerate(pref):
            target = val - sumTar
            if target in firstIdx:
                maxLen = max(maxLen, i - firstIdx[target])

            if val not in firstIdx: 
                firstIdx[val] = i

        if maxLen == -1:
            return -1
        return n - maxLen



