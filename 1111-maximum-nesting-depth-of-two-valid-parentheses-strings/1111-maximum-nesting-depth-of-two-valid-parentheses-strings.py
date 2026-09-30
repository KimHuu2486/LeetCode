class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        n = len(seq)
        ans = [0] * n
        balance = 0

        for i in range(0, n):
            if seq[i] == '(':
                balance += 1
                ans[i] = balance % 2
            else:
                ans[i] = balance % 2
                balance -= 1
        
        return ans