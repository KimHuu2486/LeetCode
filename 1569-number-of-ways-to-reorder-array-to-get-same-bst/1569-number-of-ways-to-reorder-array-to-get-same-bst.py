
import math

class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        MOD = 10**9 + 7

        def dfs(arr):
            n = len(arr)
            if n <= 1:
                return 1

            root = arr[0]
            left = [x for x in arr if x < root]
            right = [x for x in arr if x > root]

            a, b = len(left), len(right)

            return (
                math.comb(a + b, a)
                * dfs(left)
                * dfs(right)
            ) % MOD

        return (dfs(nums) - 1) % MOD
