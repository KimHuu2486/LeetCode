class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        free = [(weight, i) for i, weight in enumerate(servers)]
        heapq.heapify(free)

        busy = []
        ans = []
        time = 0

        for j, duration in enumerate(tasks):
            time = max(time, j)

            while busy and busy[0][0] <= time:
                finish, weight, i = heapq.heappop(busy)
                heapq.heappush(free, (weight, i))

            if not free:
                time = busy[0][0]

                while busy and busy[0][0] <= time:
                    finish, weight, i = heapq.heappop(busy)
                    heapq.heappush(free, (weight, i))

            weight, i = heapq.heappop(free)
            ans.append(i)

            heapq.heappush(busy, (time + duration, weight, i))

        return ans