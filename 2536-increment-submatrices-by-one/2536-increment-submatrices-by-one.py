class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        for [r1, c1, r2, c2] in queries:
            for i in range (r1, r2 + 1):
                ans[i][c1] += 1
                if c2 + 1 < n:
                    ans[i][c2 + 1] -= 1
        for i in range (0, n):
            for j in range (1, n):
                ans[i][j] += ans[i][j-1]
        return ans