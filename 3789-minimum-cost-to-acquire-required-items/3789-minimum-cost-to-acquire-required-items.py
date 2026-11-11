class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        init = min(need1, need2)
        ans = min(costBoth * init, cost1 * init + cost2 * init)

        diff1, diff2 = need1 - init, need2 - init
        ans += min(costBoth * diff1, cost1 * diff1) + min(costBoth * diff2, cost2 * diff2)

        return ans
            