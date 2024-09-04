class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, amount+1));
        for(int i = 0; i < coins.size(); i++)
        {
            dp[i][0] = 0;
        }

        for(int i = 1; i < coins.size()+1; i++)
        {
            for(int j = 0; j < amount+1; j++)
            {
                int target = (j)-coins[i-1];
                if(target >= 0)
                {
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][target]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (dp[coins.size()][amount] > amount ? -1 : dp[coins.size()][amount]);
    }
};