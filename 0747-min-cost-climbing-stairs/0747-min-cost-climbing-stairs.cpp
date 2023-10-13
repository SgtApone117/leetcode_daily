class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = (int)cost.size();
        if(n == 2)
            return min(cost[0], cost[1]);
        for(int i = 2; i < n; i++)
        {
            cost[i] += min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};