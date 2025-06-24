class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        res = []
        r = 0
        for j in range(n):
            if nums[j] == key:
                l = max(r,j-k)
                r = min(n-1,j+k) + 1
                for i in range(l,r):
                    res.append(i)
        return res