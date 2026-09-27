class Solution:
    def reverseParentheses(self, s: str) -> str:
        st = []
        cur = ""
        for c in s:
            if c == '(':
                st.append(cur)
                cur = ""
            elif c == ')':
                cur = cur[::-1]
                cur = st.pop() + cur
            else:
                cur += c
        return cur