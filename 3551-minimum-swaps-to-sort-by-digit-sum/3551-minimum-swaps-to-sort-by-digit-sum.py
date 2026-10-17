class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def sumDigit(x):
            ans = 0
            while x > 0:
                ans += x % 10
                x //= 10
            return ans

        target = sorted(nums, key=lambda x: (sumDigit(x), x))

        pos = {v: i for i, v in enumerate(target)}
        n = len(nums)
        visited = [False] * n
        ans = 0

        for i in range(n):
            if visited[i]:
                continue

            j = i
            cycle = 0

            while not visited[j]:
                visited[j] = True
                j = pos[nums[j]]
                cycle += 1

            ans += cycle - 1

        return ans