class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        def solve(arr, d, i, dp):
            if dp[i] != -1:
                return dp[i]

            cnt = 1

            # Move left:
            for jump in range(1, d + 1):
                if i - jump < 0:
                    break
                if arr[i] > arr[i - jump]:
                    cnt = max(cnt, 1 + solve(arr, d, i - jump, dp))
                else:
                    break

            # Move right
            for jump in range(1, d + 1):
                if i + jump >= len(arr):
                    break
                if arr[i] > arr[i + jump]:
                    cnt = max(cnt, 1 + solve(arr, d, i + jump, dp))
                else:
                    break

            dp[i] = cnt
            return cnt

        n = len(arr)
        dp = [-1] * n
        ans = 1

        for i in range(n):
            ans = max(ans, solve(arr, d, i, dp))

        return ans
