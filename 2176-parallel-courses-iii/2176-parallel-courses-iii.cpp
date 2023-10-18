class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        for(int i = 0; i < relations.size(); i++)
        {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;
        vector<int> maxTime(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0)
            {
                que.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!que.empty())
        {
            int u = que.front();
            que.pop();

            for(int &v : adj[u])
            {
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);
                inDegree[v]--;
                if(inDegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }

        return *max_element(begin(maxTime), end(maxTime));
    }
};