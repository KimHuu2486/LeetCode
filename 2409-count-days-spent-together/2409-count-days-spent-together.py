class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        start = max(arriveAlice, arriveBob)
        end = min(leaveAlice, leaveBob)

        if start > end:
          return 0

        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        def to_day_of_year(date: str) -> int:
          m, d = map(int, date.split("-"))
          return sum(days[: m - 1]) + d

        return to_day_of_year(end) - to_day_of_year(start) + 1
