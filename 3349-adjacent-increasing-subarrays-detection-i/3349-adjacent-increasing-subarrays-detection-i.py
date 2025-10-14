class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        for i in range(n - 2 * k + 1):
            inc1 = True
            inc2 = True
            for j in range(i + 1, i + k):
                if nums[j] <= nums[j - 1]:
                    inc1 = False
                    break
            for j in range(i + k + 1, i + 2 * k):
                if nums[j] <= nums[j - 1]:
                    inc2 = False
                    break
            if inc1 and inc2:
                return True
        return False
