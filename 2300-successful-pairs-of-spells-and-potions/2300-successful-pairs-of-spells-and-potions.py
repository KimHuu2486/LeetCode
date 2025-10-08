class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        n = len(spells)
        m = len(potions)
        potions.sort()
        ans = [0] * n
        for i in range(n):
            need = (success + spells[i] - 1)// spells[i]
            left = 0
            right = m - 1
            while left <= right:
                mid = left + (right - left) // 2
                if potions[mid] < need:
                    left = mid + 1
                else:
                    right = mid - 1
            ans[i] = m - left
        return ans
        