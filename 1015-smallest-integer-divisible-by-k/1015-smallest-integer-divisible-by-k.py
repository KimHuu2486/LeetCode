class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        length = 0
        rem = 0
        for _ in range(k):
            rem = (rem * 10 + 1) % k
            length += 1
            if rem == 0:
                return length
        return -1
