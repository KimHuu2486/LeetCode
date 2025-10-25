class Solution:
    def totalMoney(self, n: int) -> int:
        week = n // 7
        days = n % 7
        money = 28 * week + 7 * (week - 1) * week // 2
        start = week + 1
        while days:
            money += start
            start += 1
            days -= 1
        return money
