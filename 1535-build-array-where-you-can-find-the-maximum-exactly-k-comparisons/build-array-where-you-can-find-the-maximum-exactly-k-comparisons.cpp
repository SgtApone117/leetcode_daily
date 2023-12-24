class Solution {
public:
    int dp[51][51][101];
    int N,M,K;
    int solve(int idx, int lenList, int lar)
    {
        if(idx == N)
        {
            if(lenList == K)
            {
                return 1;
            }
            return 0;
        }
        if(dp[idx][lenList][lar] != -1)            
            return dp[idx][lenList][lar];
        int ans = 0;
        for(int i = 1; i <= M; i++)
        {
            if(i > lar)
            {
                ans += solve(idx+1, lenList+1, i);
            }
            else
            {
                ans += solve(idx+1, lenList, lar);
            }
            ans = ans % 1000000007;
        }
        return dp[idx][lenList][lar] = ans;
    }
    int numOfArrays(int n, int m, int k) 
    {  
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0,0,0);
    }
};