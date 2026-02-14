class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        row = [poured]

        for r in range(query_row):
            next_row = [0.0] * (r + 2)

            for c in range(len(row)):
                if row[c] > 1.0:
                    overflow = (row[c] - 1.0) / 2.0
                    next_row[c] += overflow
                    next_row[c + 1] += overflow

            row = next_row
        
        return min(1.0, row[query_glass])
