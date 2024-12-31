class Solution {
public:
    int t[366];
    int solve(vector<int>& days, vector<int>& costs, int& n, int idx)
    {
        if(idx >= n) return 0;
        if(t[idx] != -1) return t[idx];
        int cost_0 = costs[0]+solve(days,costs,n,idx+1);

        int j = idx;
        int max_days = days[idx]+7;
        while(j < n && days[j] < max_days) j++;
        int cost_7 = costs[1]+solve(days,costs,n,j);

        j = idx;
        max_days = days[idx]+30;
        while(j < n && days[j] < max_days) j++;
        int cost_30 = costs[2]+solve(days,costs,n,j);

        return t[idx] = min({cost_0,cost_7,cost_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(t,-1,sizeof(t));
        return solve(days, costs, n, 0);
    }
};