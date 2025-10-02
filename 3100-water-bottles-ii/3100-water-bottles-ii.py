class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        ans = 0
        empty = 0
        while numBottles > 0 or empty >= numExchange:
            ans += numBottles
            empty += numBottles
            numBottles = 0
            while empty >= numExchange:
                empty -= numExchange
                numBottles += 1
                numExchange +=1
        return ans            