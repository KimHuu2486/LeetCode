class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        cnt = 0

        def dfs(parent, u):
            nonlocal cnt
            
            for v in adj[u]:
                if v != parent:
                    dfs(u, v)
            
            if values[u] % k == 0:
                cnt += 1
            else:
                values[parent] = (values[parent] + values[u]) % k
        
        dfs(-1, 0)
        return cnt