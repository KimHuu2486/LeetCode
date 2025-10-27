class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev = 0
        ans = 0
        for i in range(0, len(bank)):
            cnt = bank[i].count("1")
            if cnt > 0:
                ans += prev * cnt
                prev = cnt
        return ans
