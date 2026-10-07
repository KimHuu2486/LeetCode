class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        
        def checkValid(s):
            balance = 0

            for c in s:
                if c == '(':
                    balance += 1
                elif c == ')':
                    balance -= 1

                if balance < 0:
                    return False

            return balance == 0

        queue = [s]
        visited = {s}

        while queue:
            next_queue = []
            ans = []

            for cur in queue:
                if checkValid(cur):
                    ans.append(cur)

            if ans:
                return ans

            for cur in queue:
                for i in range(len(cur)):
                    
                    if cur[i] not in '()':
                        continue

                    new_s = cur[:i] + cur[i+1:]

                    if new_s not in visited:
                        visited.add(new_s)
                        next_queue.append(new_s)

            queue = next_queue

        return [""]