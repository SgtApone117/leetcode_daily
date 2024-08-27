class Solution {
public:
    typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        
        priority_queue<P> pq;
        vector<double> result(n, 0);
        result[start_node] = 1;
        pq.push({1.0, start_node});
        while(!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &vec : adj[node])
            {
                int adjNode = vec.first;
                double adjProb = vec.second;

                if(adjProb*prob > result[adjNode])
                {
                    result[adjNode] = adjProb*prob;
                    pq.push({adjProb*prob, adjNode});
                }
            }
        }
        return result[end_node];
    }
};