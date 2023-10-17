class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        unordered_map<int,int> child_to_parent;
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < n; i++)
        {
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1)
            {
                adj[node].push_back(leftC);
                if(child_to_parent.find(leftC) != child_to_parent.end())
                {
                    return false;
                }
                child_to_parent[leftC] = node;
            }
            if(rightC != -1)
            {
                adj[node].push_back(rightC);
                if(child_to_parent.find(rightC) != child_to_parent.end())
                {
                    return false;
                }
                child_to_parent[rightC] = node;
            }
        }

        int root = -1;
        for(int i = 0; i < n; i++)
        {
            if(child_to_parent.find(i) == child_to_parent.end())
            {
                if(root != -1)
                {
                    return false;
                }
                root = i;
            }
        }

        if(root == -1)
        {
            return false;
        }

        int count = 0;
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        count = 1;
        visited[root] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int &v : adj[node])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    count++;
                    q.push(v);
                }
            }
        }
        return count == n;
    }
};