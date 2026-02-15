class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a) - 1, len(b) - 1
        res = []
        remember = 0
        while i >= 0 or j >= 0 or remember > 0:
            temp = remember
            if i >= 0:
                temp += int(a[i])
                i -= 1
            if j >= 0:
                temp += int(b[j])
                j -= 1
            res.append(str(temp % 2))
            remember = temp // 2
        return "".join(res[::-1])
