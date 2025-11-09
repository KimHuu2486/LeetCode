class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        a = max(num1, num2)
        b = min(num1, num2)
        count = 0
        while a and b:
            count += a // b
            a %= b
            a, b = b, a
        return count