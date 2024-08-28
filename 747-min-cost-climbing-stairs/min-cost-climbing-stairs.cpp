class Solution {
public:
    int t[1001];
    int solve(int idx, vector<int>& cost, int size)
    {
        if(idx >= size)
            return 0;
        if(-1 != t[idx])
            return t[idx];
        return t[idx] = cost[idx]+min(solve(idx+1, cost, size),solve(idx+2, cost,size));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return min(solve(0, cost, n),solve(1,cost,n));
    }
};