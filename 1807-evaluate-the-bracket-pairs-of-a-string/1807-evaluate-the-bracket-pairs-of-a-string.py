class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        mp = {}
        for cur in knowledge:
            mp[cur[0]] = cur[1]
        
        ans = ""
        n = len(s)
        i = 0
        while i < n:
            if s[i] != '(':
                ans += s[i]
            else:
                j = i + 1
                while j < n and s[j] != ')':
                    j += 1
                key = s[i + 1: j]
                
                if key in mp:
                    ans += mp[key]
                else:
                    ans += '?'
                i = j
            i+=1
        return ans
            
