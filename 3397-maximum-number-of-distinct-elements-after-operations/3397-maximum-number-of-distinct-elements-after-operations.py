class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        nums[0]-=k
        cnt = 1
        for i in range (1, len(nums)):
            if (nums[i] - k > nums[i-1]) :
                nums[i]-=k
                cnt+=1
            elif (nums[i] + k <= nums[i - 1]) :
               nums[i] = nums[i-1]
            else:
                nums[i] = nums[i-1] + 1
                cnt+=1
        return cnt 