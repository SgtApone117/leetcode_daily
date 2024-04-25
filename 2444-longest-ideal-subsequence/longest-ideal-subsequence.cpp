class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {0};
        int maxLen = 0;
        for(char c : s)
        {
            for(int i = c-k; i <= c+k; i++)
            {
                if(i >= 'a' && i <= 'z')
                {
                    dp[c] = max(dp[c], dp[i]);
                }
            }
            maxLen = max(++dp[c], maxLen);
        }
        return maxLen;
    }
};