class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            if (num >= 10 and num < 100) or (num >= 1000 and num < 10000) or (num == 100000):
                res += 1
        return res
        