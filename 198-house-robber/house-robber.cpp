class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        int maxProfit = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                dp[i+1] = nums[i];
                maxProfit = max(maxProfit, dp[i+1]);
                cout << dp[i+1] << " ";
                continue;
            }
            dp[i+1] = max(nums[i]+dp[i-1], maxProfit);
            cout << dp[i+1] << " ";
            maxProfit = max(dp[i+1],maxProfit);
        }
        return maxProfit;
    }
};