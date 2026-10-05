class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ans = 0
        depth = 0

        for i, c in enumerate(s):
            if c == '(':
                depth += 1
            else:
                depth -= 1

                if s[i - 1] == '(':
                    ans += 2 ** depth

        return ans
