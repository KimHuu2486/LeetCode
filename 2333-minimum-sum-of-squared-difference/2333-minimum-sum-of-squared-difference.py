class Solution:
    def minSumSquareDiff(
        self, nums1: list[int], nums2: list[int], k1: int, k2: int
    ) -> int:
        nums = [abs(a - b) for a, b in zip(nums1, nums2)]
        k = k1 + k2

        if sum(nums) <= k:
            return 0

        left, right = 0, max(nums)

        while left < right:
            mid = (left + right) // 2

            operations = sum(max(0, x - mid) for x in nums)

            if operations <= k:
                right = mid
            else:
                left = mid + 1

        threshold = left

        used = sum(max(0, x - threshold) for x in nums)
        remaining = k - used

        ans = 0

        for x in nums:
            value = min(x, threshold)

            if value == threshold and remaining > 0:
                value -= 1
                remaining -= 1

            ans += value * value

        return ans
