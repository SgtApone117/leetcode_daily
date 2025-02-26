class Solution:
    def maxSubarraySum(self, nums: List[int]) -> int:
        currSum = nums[0]
        maxSum = nums[0]
        for i in range(1, len(nums)):
            currSum = max(nums[i], currSum+nums[i])
            maxSum  = max(currSum, maxSum)
        return maxSum 
    def minSubarraySum(self, nums: List[int]) -> int:
        currSum = nums[0]
        minSum = nums[0]
        for i in range(1, len(nums)):
            currSum = min(nums[i], currSum+nums[i])
            minSum  = min(currSum, minSum)
        return abs(minSum)
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        return max(self.maxSubarraySum(nums), self.minSubarraySum(nums))