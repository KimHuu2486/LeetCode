class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans, bal = 0, 0
        
        for c in s:
            if c == '(':
                bal += 1
            else:
                if bal > 0:
                    bal -= 1
                else:
                    ans += 1
        return ans + bal