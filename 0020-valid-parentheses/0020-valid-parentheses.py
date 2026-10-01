class Solution:
    def isValid(self, s: str) -> bool:
        valid = {')': '(', ']': '[', '}': '{'}
        stack = []

        for c in s:
            if c not in valid:
                stack.append(c)
            else:
                if not stack:
                    return False
                    
                cur = stack.pop()

                if valid[c] != cur:
                    return False

        return not stack
