class Solution {
public:
    vector<int> result;
    void dfs(int u, int prev, unordered_map<int, vector<int>> &adj)
    {
        result.emplace_back(u);
        for(int &v : adj[u])
        {
            if(v!=prev)
            {
                dfs(v,u,adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &vec : adjacentPairs)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        int startPoint = -1;
        for(auto &it : adj)
        {
            if(it.second.size() == 1)
            {
                startPoint = it.first;
            }
        }
        dfs(startPoint, INT_MIN, adj);
        return result;
    }
};