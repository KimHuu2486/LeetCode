class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        n = len(arr2)

        def binarySearch(left, right, val):
            if left == right:
                return arr2[left]
            if right - 1 == left:
                if abs(arr2[right] - val) > abs(arr2[left] - val):
                    return arr2[left]
                else:
                    return arr2[right]

            mid = left + (right - left) // 2
            if arr2[mid] == val:
                return arr2[mid]
            elif arr2[mid] < val:
                return binarySearch(mid, right, val)
            else:
                return binarySearch(left, mid, val)

        ans = 0
        for num in arr1:
            if abs(num - binarySearch(0, n - 1, num)) <= d:
                continue
            ans += 1

        return ans