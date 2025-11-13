class Solution:
    def maxOperations(self, s: str) -> int:
        s = s + '1'
        cnt1 = 0
        ans = 0

        n_minus_1 = len(s) - 1
        s_local = s

        for i in range(n_minus_1):
            c = s_local[i]
            if c == '1':
                cnt1 += 1
            else:
                if s_local[i+1] == '1':
                    ans += cnt1

        return ans