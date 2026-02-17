class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        value = [8, 4, 2, 1, 32, 16, 8, 4, 2, 1]
        ans = []

        def backtracking(count, start, hour, minute):
            if hour > 11 or minute > 59:
                return

            if count == 0:
                ans.append(f"{hour}:{minute:02d}")
                return

            for i in range(start, 10):
                if i < 4:
                    backtracking(count - 1, i + 1, hour + value[i], minute)
                else:
                    backtracking(count - 1, i + 1, hour, minute + value[i])
        
        backtracking(turnedOn, 0, 0, 0)
        return ans