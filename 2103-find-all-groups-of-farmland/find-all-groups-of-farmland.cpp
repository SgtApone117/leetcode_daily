class Solution {
public:
    void dfs(vector<vector<int>>& land, int row, int col, int i, int j, int& r2, int& c2, vector<vector<int>>& result)
    {
        if(i < 0 || i >= row || j < 0 || j >= col || land[i][j] != 1)
        {
            return;
        }

        r2 = max(i, r2);
        c2 = max(j, c2);
        land[i][j] = -1;
        dfs(land, row, col, i+1, j, r2, c2, result);
        dfs(land, row, col, i-1, j, r2, c2, result);
        dfs(land, row, col, i, j+1, r2, c2, result);
        dfs(land, row, col, i, j-1, r2, c2, result);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> result;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(land[i][j] == 1)
                {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    dfs(land, m, n, i, j, r2, c2, result);
                    cout << r2 << " " << c2 << endl;
                    result.push_back({r1,c1,r2,c2});
                }
            }
        }
        return result;
    }
};