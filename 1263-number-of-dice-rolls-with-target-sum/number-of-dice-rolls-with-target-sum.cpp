class Solution {
public:
    int t[31][1001];
    int MOD = 1e9+7;
    int solve(int n, int k, int target)
    {
        if(0 > target)
        {
            return 0;
        }

        if(-1 != t[n][target])
        {
            return t[n][target];
        }
        if(0 == n)
        {
            return target == 0;
        }
        int ways = 0;
        for(int face = 1; face <= k; face++)
        {
            ways = (ways + solve(n-1, k, target-face)) % MOD;
        }
        return t[n][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(t, -1, sizeof(t));
        return solve(n, k, target);
    }
};