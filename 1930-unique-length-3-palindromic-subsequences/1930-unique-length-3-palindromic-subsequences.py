class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        count = 0
        first = [-1] * 26
        last = [-1] * 26
        n = len(s)

        for i in range(n):
            idx = ord(s[i]) - ord('a')
            if first[idx] == -1:
                first[idx] = i
            last[idx] = i

        for i in range(26):
            if first[i] != -1 and last[i] - first[i] > 1:
                temp = set()
                for j in range(first[i] + 1, last[i]):
                    temp.add(s[j])
                count += len(temp)

        return count
