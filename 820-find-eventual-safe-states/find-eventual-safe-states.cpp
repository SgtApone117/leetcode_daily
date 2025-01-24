class Solution {
public:

    bool dfs(vector<int> adj[], int i, vector<int> &vis, vector<int> &pathvis){
        // storing node that has been visited
        vis[i]=1;
        // storing the path that has been visited
        pathvis[i]=1;
        for(auto j : adj[i]){
            if(!vis[j]){
                // marking all nodes in the cycle
                if(dfs(adj, j, vis, pathvis)==1){
                    vis[i]=2;
                    return 1;
                }
            }
            // if vis and pathvis then cycle is present
            else if(pathvis[j]){
                vis[i]=2;
                return 1;
            }
        }
        // removing path since we are returning
        pathvis[i]=0;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> adj[V];
        // making adjency list
        for(int i=0; i<V; i++){
            for(auto j : graph[i]) adj[i].push_back(j);
        }
        //  calling dfs
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(adj, i, vis, pathvis);
            }
        }
        // storing nodes that aren't in the cycle
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(vis[i]!=2) ans.push_back(i);
        }
        return ans;
    }
};