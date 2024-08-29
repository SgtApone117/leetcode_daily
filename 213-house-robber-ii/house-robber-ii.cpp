class Solution {
public:
    int getMaxProfit(vector<int>& nums, int n)
    {
        vector<int> dp(n+1);
        dp[0] = 0;
        int maxProfit = 0;
        dp[1] = max(nums[0], maxProfit);
        maxProfit = max(maxProfit, dp[1]);
        for(int i = 2; i <= n; i++)
        {
            int profit = nums[i-1]+dp[i-2];
            maxProfit = max(maxProfit, profit);
            dp[i] = maxProfit;
        }
        return maxProfit;
    }

    int getMaxProfit2(vector<int>& nums, int n)
    {
        vector<int> dp((2*n)+1);
        dp[0] = 0;
        int maxProfit = 0;
        dp[1] = max(nums[0], maxProfit);
        maxProfit = max(maxProfit, dp[1]);
        for(int i = 2; i <= 2*n; i++)
        {
            int profit = nums[(i-1)%n]+dp[i-2];
            maxProfit = max(maxProfit, profit);
            dp[i] = maxProfit;
        }
        return maxProfit;
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n <= 1)
            return nums[0];
        cout << getMaxProfit2(nums, n) << endl;
        cout << getMaxProfit(nums, n) << endl;
        return getMaxProfit2(nums, n)-getMaxProfit(nums, n);
    }
};