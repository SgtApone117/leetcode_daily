class Solution {
public:
    void dfs(vector<vector<int>>& grid, int &perimeter, int row, int col, int i, int j)
    {
        cout << perimeter << endl;
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0)
        {
            perimeter++;
            return;
        }
        if(grid[i][j] == -1)
        {
            return;
        }
        grid[i][j] = -1;

        dfs(grid, perimeter, row, col, i+1, j);
        dfs(grid, perimeter, row, col, i-1, j);
        dfs(grid, perimeter, row, col, i, j+1);
        dfs(grid, perimeter, row, col, i, j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid, perimeter, m, n,i, j);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};