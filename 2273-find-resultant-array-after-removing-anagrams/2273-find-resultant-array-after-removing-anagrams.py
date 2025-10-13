class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        ans = [words[0]]
        prev = "".join(sorted(words[0]))
        for i in range (1, len(words)):
            temp = "".join(sorted(words[i]))
            if (temp != prev) :
                ans.append(words[i])
                prev = temp
        return ans