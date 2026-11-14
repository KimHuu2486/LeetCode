class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n, m = len(nums), l
        ans = 10 ** 9
        init_sum = sum(nums[0 : m - 1])

        while m <= r:
            init_sum += nums[m - 1]
            cur_sum = init_sum
            if cur_sum > 0:
                ans = min(ans, cur_sum)
            
            for i in range(m, n):
                cur_sum += nums[i] - nums[i - m]
                if cur_sum > 0:
                    ans = min(ans, cur_sum)

            m += 1
        
        if ans == 10 ** 9:
            return -1
        return ans
            