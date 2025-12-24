class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        totalApple = sum(apple)

        capacity.sort(reverse = True)

        cnt = 0
        while totalApple > 0 :
            totalApple -= capacity[cnt]
            cnt += 1
        

        return cnt