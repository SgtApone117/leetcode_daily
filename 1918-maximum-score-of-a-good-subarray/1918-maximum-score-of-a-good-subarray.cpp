class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i = k;
        int j = k;
        int currVal = nums[k];
        int result = nums[k];

        while(i > 0 || j < n-1)
        {
            int left = (i > 0) ? nums[i-1] : 0;
            int right = (j < n-1)? nums[j+1] : 0;
            if(left > right)
            {
                i--;
                currVal = min(currVal, nums[i]);
            }
            else
            {
                j++;
                currVal = min(currVal, nums[j]);
            }
            result = max(result, currVal*(j-i+1));
        }

        return result;
    }
};