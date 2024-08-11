class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] == 0)
            return;
        vis[i][j] = true;

        DFS(grid, i-1, j, vis);
        DFS(grid, i+1, j, vis);
        DFS(grid, i, j-1, vis);
        DFS(grid, i, j+1, vis);
    }
    int getIslandCount(vector<vector<int>>& grid)
    {
        int islands = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    DFS(grid, i, j, vis);
                    islands += 1;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = getIslandCount(grid);

        if(island > 1 || island == 0)
        {
            return 0;
        }
        else
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        grid[i][j] = 0;
                        island = getIslandCount(grid);
                        grid[i][j] = 1;
                        if(island > 1 || island == 0)
                            return 1;
                    }

                }
            }
        }
        
        return 2;
    }
};