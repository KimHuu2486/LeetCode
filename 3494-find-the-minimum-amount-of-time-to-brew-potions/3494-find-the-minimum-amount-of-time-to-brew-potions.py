class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n = len(skill)
        done = [0] * (n + 1)
        for j in mana:
            for i in range(n):
                done[i + 1] = max(done[i], done[i + 1]) + j * skill[i]
            for i in range(n - 1, 0, -1):
                done[i] = done[i + 1] - j * skill[i]
        return done[n]
