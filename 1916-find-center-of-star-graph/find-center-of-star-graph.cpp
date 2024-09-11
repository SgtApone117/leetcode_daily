class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge : edges)
        {
            int v = edge[0];
            int u = edge[1];

            adj[v].push_back(u);
            adj[u].push_back(v);
            if(adj[v].size() > 1)
                return v;
            if(adj[u].size() > 1)
                return u;
        }
        return 1;
    }
};