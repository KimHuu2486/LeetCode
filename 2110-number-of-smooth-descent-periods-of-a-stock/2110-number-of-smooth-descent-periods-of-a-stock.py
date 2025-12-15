class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        prevPrice = -1
        curStreak = 1
        ans = 0
        for price in prices:
            if price > 0 and prevPrice - price == 1:
                curStreak += 1
                ans += curStreak
            else:
                curStreak = 1
                ans += 1
            prevPrice = price
        return ans