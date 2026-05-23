class Solution:
    def check(self, nums: List[int]) -> bool:
        cntDesc = 0
        n = len(nums)
        for i in range(n - 1):
            if nums[i + 1] < nums[i]:
                cntDesc += 1
                if cntDesc > 1:
                    return False
        if nums[n - 1] > nums[0] and cntDesc > 0:
            return False
        return True
