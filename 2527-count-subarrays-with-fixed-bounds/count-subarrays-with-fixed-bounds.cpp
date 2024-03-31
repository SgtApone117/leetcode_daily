class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        
        int minPosition = -1;
        int maxPosition = -1;
        int outOfBound  = -1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                outOfBound = i;
            }
            if(nums[i] == maxK)
            {
                maxPosition = i;
            }
            if(nums[i] == minK)
            {
                minPosition = i;
            }
            long long smallerIdx = min(minPosition, maxPosition);
            
            long long temp = smallerIdx - outOfBound;
            
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};