class Solution {
private:
    int dfs(vector<int> adj[], int source, int destination, int vis[])
    {
        if(source == destination)
            return 1;
        if(vis[source] == 1)
            return 0;
        vis[source] = 1;

        for(auto it : adj[source])
        {
            if(dfs(adj, it, destination, vis) == 1)
            {
                return 1;
            }
        }
        return 0;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        int vis[n];
        memset(vis, 0, sizeof(vis));
        vector<int> adj[n];
        for(vector<int>& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(dfs(adj, source, destination, vis) == 1)
            return true;
        return false;
    }
};