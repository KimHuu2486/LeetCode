class Solution:
    def checkString(self, s: str) -> bool:
        n = len(s)
        for i in range(n - 1):
            if s[i + 1] == 'a' and s[i] == 'b':
                return False
        return True