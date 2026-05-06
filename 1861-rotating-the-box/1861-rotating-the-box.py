class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        rotated_box = [list(row) for row in zip(*boxGrid[::-1])]

        n, m = len(rotated_box) , len(rotated_box[0])

        for j in range(m):
            bottom = n - 1
            for i in range (n - 1, -1, -1):
                if rotated_box[i][j] == '*':
                    bottom = i - 1
                elif rotated_box[i][j] == '#':
                    if bottom != i:
                        rotated_box[bottom][j] = '#'
                        rotated_box[i][j] = '.'
                    bottom -= 1

        return rotated_box