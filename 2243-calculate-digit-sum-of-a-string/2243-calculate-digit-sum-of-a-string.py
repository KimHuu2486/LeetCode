class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            s_new = ""
            left, right, n = 0, k, len(s)

            while (left < n):
                s_new = s_new + str(sum(map(int, s[left:min(right, n)])))
                left += k
                right += k
        
            s = s_new
        
        return s
