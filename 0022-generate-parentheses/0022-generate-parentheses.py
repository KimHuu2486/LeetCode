class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans = []

        def generate(temp, open, close):
            if len(temp) == 2 * n:
                ans.append(temp)
                return
            if open < n:
                generate(temp + '(', open + 1, close)
            if open > close:
                generate(temp + ')', open, close + 1)
        
        generate('', 0, 0)
        return ans