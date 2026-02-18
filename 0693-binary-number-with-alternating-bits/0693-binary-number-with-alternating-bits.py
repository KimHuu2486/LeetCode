class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        cur = n & 1
        n >>= 1
        while n > 0:
            nxt = n & 1
            if cur == nxt:
                return False
            cur = nxt
            n >>= 1
        return True
