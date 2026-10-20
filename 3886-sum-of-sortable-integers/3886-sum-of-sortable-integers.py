class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        ans, n = 0, len(nums)
        sortedNums = sorted(nums)

        def cntDecreasing(arr):
            cnt = 0
            m = len(arr)

            for i in range(m):
                if arr[i] > arr[(i + 1) % m]:
                    cnt += 1
                    if cnt > 1:
                        break

            return cnt

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            valid = True

            for l in range(0, n, k):
                r = l + k
                temp = nums[l:r]

                if cntDecreasing(temp) > 1:
                    valid = False
                    break

                if sorted(temp) != sortedNums[l:r]:
                    valid = False
                    break

            if valid:
                ans += k

        return ans
