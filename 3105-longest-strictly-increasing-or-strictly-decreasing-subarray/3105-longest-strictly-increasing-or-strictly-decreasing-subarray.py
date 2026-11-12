class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        inc, des = 1, 1
        n = len(nums)
        
        cur_inc, cur_des = inc, des
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                cur_inc += 1
            else:
                cur_inc = 1
            if nums[i] < nums[i - 1]:
                cur_des += 1
            else:
                cur_des = 1
            inc = max(inc, cur_inc)
            des = max(des, cur_des)
        return max(inc, des)
        
        