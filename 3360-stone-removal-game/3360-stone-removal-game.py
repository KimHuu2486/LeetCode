class Solution:
    def canAliceWin(self, n: int) -> bool:
        turn = 0
        cur = 10
        while n >= cur:
            n -= cur
            turn += 1
            cur -= 1
        return bool(turn % 2)