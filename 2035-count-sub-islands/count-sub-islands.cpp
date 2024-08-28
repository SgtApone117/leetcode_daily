class Solution {
public:
    bool checkIfIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j)
    {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size())
        {
            return true;
        }

        if(grid2[i][j] != 1)
            return true;
        grid2[i][j] = -1;

        int result = (grid1[i][j] == 1);

        result = result & checkIfIsland(grid1, grid2, i+1, j);
        result = result & checkIfIsland(grid1, grid2, i-1, j);
        result = result & checkIfIsland(grid1, grid2, i, j+1);
        result = result & checkIfIsland(grid1, grid2, i, j-1);

        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        int subIsland = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid2[i][j] == 1 && checkIfIsland(grid1, grid2, i, j))
                {
                    subIsland++;
                }
            }
        }
        return subIsland;
    }
};