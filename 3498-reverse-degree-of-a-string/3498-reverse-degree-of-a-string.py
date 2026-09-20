class Solution:
    def reverseDegree(self, s: str) -> int:
        sum, n = 0, len(s)
        for i in range(0, n):
            sum += (26 + ord('a') - ord(s[i])) * (i + 1)

        return sum
         
        