class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col)
    {
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1')
            return;
        if(grid[i][j] == '&')
            return;
        grid[i][j] = '&';

        dfs(grid, i+1, j, row, col);
        dfs(grid, i-1, j , row, col);
        dfs(grid, i, j+1, row, col);
        dfs(grid, i, j-1, row, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n);
                    count++;
                }
            }
        }

        return count;
    }
};