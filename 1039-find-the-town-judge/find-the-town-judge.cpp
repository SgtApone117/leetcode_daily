class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n+1);
        vector<int> outDegree(n+1);

        for(vector<int> &person : trust)
        {
            int u = person[0];
            int v = person[1];

            inDegree[u]++;
            outDegree[v]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(outDegree[i] == n-1 && inDegree[i] <= 0)
            {
                return i;
            }
        }
        return -1;
    }
};