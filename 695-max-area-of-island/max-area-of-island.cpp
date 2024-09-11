class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &getNewCount)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;
        getNewCount++; // get total islands formed
        grid[i][j] = 0; //mark visited
        dfs(grid, i+1, j, getNewCount);
        dfs(grid, i-1, j, getNewCount);
        dfs(grid, i, j+1, getNewCount);
        dfs(grid, i, j-1, getNewCount);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int maxIsland = 0;
       for(int i = 0; i < grid.size(); i++)
       {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(1 == grid[i][j])
                {
                    int getNewCount = 0;
                    dfs(grid, i,j, getNewCount);
                    maxIsland = max(getNewCount, maxIsland);
                }
            }
       }
       return maxIsland;
    }
};