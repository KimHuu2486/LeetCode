class Solution:
    def pancakeSort(self, arr: list[int]) -> list[int]:
        n = len(arr)
        ans = []

        for target in range(n, 1, -1):
            idx = arr.index(target)
            if (idx == target - 1):
                continue
            
            if idx > 0:
                arr[:idx + 1] = arr[:idx + 1][::-1]
                ans.append(idx + 1)
            
            arr[:target] = arr[:target][::-1]
            ans.append(target)
        
        return ans
