class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = (10**9)+7
        prefix_sum = []
        curr_s = 0
        for num in arr:
            curr_s += num
            prefix_sum.append(curr_s)
        even  = 1
        odd   = 0
        count = 0
        for num in prefix_sum:
            if num % 2 == 0:
                count = (count + odd) % MOD
                even += 1
            else:
                count = (count + even) % MOD
                odd += 1
        return count 
        
        