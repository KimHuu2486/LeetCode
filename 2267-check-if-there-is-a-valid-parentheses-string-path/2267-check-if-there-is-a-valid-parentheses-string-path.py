class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])

        length = m + n - 1

        if length % 2 == 1:
            return False

        if grid[0][0] != '(':
            return False

        if grid[m - 1][n - 1] != ')':
            return False

        k = length // 2

        dp = [ [ [False] * (k + 1) for _ in range(n)] for _ in range(m) ]

        dp[0][0][1] = True

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                for bal in range(k + 1):
                    if grid[i][j] == '(':

                        prev_bal = bal - 1
                        if prev_bal >= 0:
                            if i > 0 and dp[i - 1][j][prev_bal]:
                                dp[i][j][bal] = True

                            if j > 0 and dp[i][j - 1][prev_bal]:
                                dp[i][j][bal] = True

                    else:

                        prev_bal = bal + 1
                        if prev_bal <= k:
                            if i > 0 and dp[i - 1][j][prev_bal]:
                                dp[i][j][bal] = True

                            if j > 0 and dp[i][j - 1][prev_bal]:
                                dp[i][j][bal] = True

        return dp[m - 1][n - 1][0]