class Solution:
    def validateCoupons(
        self, code: List[str], businessLine: List[str], isActive: List[bool]
    ) -> List[str]:
        def isCheckCode(code):
            if not code:
                return False
            for c in code:
                if not (c.isalnum() or c == '_'):
                    return False
            return True

        mp = {"electronics": 0, "grocery": 1, "pharmacy": 2, "restaurant": 3}
        raw = []

        n = len(code)
        for i in range(n):
            if not isActive[i] or businessLine[i] not in mp or not isCheckCode(code[i]):
                continue
            raw.append([mp[businessLine[i]], code[i]])
        
        raw.sort()
        return [s for _, s in raw]