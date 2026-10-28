class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = [["#"] * n for _ in range(m)]

        ans[0][0] = "."
        for i in range(1, m):
            ans[i][0] = "."

        for j in range(1, n):
            ans[m - 1][j] = "."
        
        return [''.join(row) for row in ans]