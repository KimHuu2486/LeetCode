class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key=lambda log: log[1])

        sorted_queries = sorted(enumerate(queries), key=lambda q: q[1])

        count = [0] * (n + 1)
        ans = [0] * len(queries)

        left = right = 0
        active = 0

        for idx, q in sorted_queries:

            while right < len(logs) and logs[right][1] <= q:
                server_id = logs[right][0]

                if count[server_id] == 0:
                    active += 1

                count[server_id] += 1
                right += 1

            while left < right and logs[left][1] < q - x:
                server_id = logs[left][0]

                count[server_id] -= 1

                if count[server_id] == 0:
                    active -= 1

                left += 1

            ans[idx] = n - active

        return ans