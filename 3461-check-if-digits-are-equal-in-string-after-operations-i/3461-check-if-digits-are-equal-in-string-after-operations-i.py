class Solution:
    def hasSameDigits(self, s: str) -> bool:
        s = list(s)
        for i in range(0, len(s) - 2):
            for j in range(0, len(s) - 1 - i):
                s[j] = str((int(s[j]) + int(s[j + 1])) % 10)
        return s[0] == s[1]
