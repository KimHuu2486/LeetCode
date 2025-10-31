class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        freq = [0] * (n - 2)
        ans = []
        for num in nums:
            freq[num]+=1
            if freq[num] >= 2:
                ans.append(num)
        return ans