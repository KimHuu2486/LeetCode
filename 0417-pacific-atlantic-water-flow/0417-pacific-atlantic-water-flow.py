class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]


    def dfs(self, heights, visited, i, j):
        visited[i][j] = True
        for k in range(4):
            x = i + self.direction[k][0]
            y = j + self.direction[k][1]
            if (
                x < 0
                or x >= self.m
                or y < 0
                or y >= self.n
                or visited[x][y] == True
                or heights[i][j] > heights[x][y]
            ):
                continue
            self.dfs(heights, visited, x, y)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.m = len(heights)
        self.n = len(heights[0])
        Pacific = [[False for _ in range(self.n)] for _ in range(self.m)]
        Atlantic = [[False for _ in range(self.n)] for _ in range(self.m)]
        for i in range(self.m):
            self.dfs(heights, Pacific, i, 0)
            self.dfs(heights, Atlantic, i, self.n - 1)
        for j in range(self.n):
            self.dfs(heights, Pacific, 0, j)
            self.dfs(heights, Atlantic, self.m - 1, j)
        ans = []
        for i in range(self.m):
            for j in range(self.n):
                if Pacific[i][j] and Atlantic[i][j]:
                    ans.append([i, j])
        return ans
