class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n = len(mat)

        def RotateRight(matrix):
            return [list(row[::-1]) for row in zip(*matrix)]

        for _ in range(4):
            if mat == target:
                return True
            mat = RotateRight(mat)
        return False