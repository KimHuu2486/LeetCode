class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        if x1 <= xCenter <= x2 and y1 <= yCenter <= y2:
            return True

        def clamp(v, a, b):
            return max(a, min(b, v))
        
        xp = clamp(xCenter, x1, x2)
        yp = clamp(yCenter, y1, y2)

        def distance(x1, y1, x2, y2):
            return sqrt((x1 - x2)**2 + (y1 - y2)**2)
        
        dis = distance(xCenter, yCenter, xp, yp)

        if dis <= radius:
            return True
        return False