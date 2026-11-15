
class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        MOD = 10**9 + 7
        odd, even = 0, 1
        parity = 0
        ans = 0

        for num in arr:
            parity = (parity + num) % 2

            if parity == 0:
                ans = (ans + odd) % MOD
                even += 1
            else:
                ans = (ans + even) % MOD
                odd += 1

        return ans
