class Solution {
public:
    int n;
    int t[501][501];
    int solve(int idx, int remain, vector<int>& cost, vector<int>& time)
    {
        if(remain <= 0)
        {
            return 0;
        }
        if(idx >= n)
        {
            return 1e9;
        }
        if(t[idx][remain] != -1)
        {
            return t[idx][remain];
        }

        int paint_idx = cost[idx] + solve(idx + 1,remain-1-time[idx], cost,time);
        int not_paint_idx = solve(idx + 1,remain, cost,time);
        return t[idx][remain] = min(paint_idx, not_paint_idx);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        n = (int)cost.size();
        memset(t,-1,sizeof(t));
        return solve(0, n, cost, time);
    }
};