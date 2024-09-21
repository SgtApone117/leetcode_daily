class Solution {
public:
    void topo(vector<vector<int>> &adjList, vector<int> &visited, stack<int> &st, int x)
    {
        if(visited[x])
            return;
        visited[x] = true;
        for(int &v : adjList[x])
        {
            topo(adjList, visited, st, v);
        }
        st.push(x);
    }

    void dfs(vector<vector<int>> &adjList, vector<int> &visited, int x, int i)
    {
        if(visited[x])
            return;
        visited[x] = true;
        i++;
        for(int &v : adjList[x])
            dfs(adjList, visited, v, i);

    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        stack<int> st;
        vector<int> visited(n, false);
        for(vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        for(int i = 0; i < n; i++)
        {
            topo(adjList, visited, st, i);
        }

        for(int i=0;i<n;i++) visited[i]=false;
        vector<int> ans;
        int i = 0;
        while(st.size() && i<n)
        {
            int val = st.top();
            st.pop();
            if(!visited[val])
            {
                ans.push_back(val);
                dfs(adjList, visited, val, i);
            }
        }
        return ans;
    }
};