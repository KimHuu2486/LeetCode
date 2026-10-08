class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = ""
        bal, start = 0, 0
        n = len(s)

        for i in range(0, n):
            if s[i] == "(":
                bal += 1
            else:
                bal -= 1
            if bal == 0:
                ans += s[start + 1 : i]
                start = i + 1
                
        return ans
