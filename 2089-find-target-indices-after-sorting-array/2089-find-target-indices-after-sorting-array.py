class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        nums.sort()
        n = len(nums)
        ans = []

        for i in range(n):
            if nums[i] == target:
                ans.append(i)
            elif nums[i] > target:
                break
        
        return ans