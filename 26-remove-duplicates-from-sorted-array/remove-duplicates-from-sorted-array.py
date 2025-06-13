class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        swap = 0
        for i in range(len(nums)):
            if nums[i] > nums[swap]:
                swap += 1
                nums[swap] = nums[i]
            i += 1
        return swap+1