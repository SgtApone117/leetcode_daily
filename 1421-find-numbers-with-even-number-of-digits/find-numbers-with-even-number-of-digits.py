class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            count = int(math.floor(math.log10(num)))+1
            if count % 2 == 0:
                res += 1
        return res
        