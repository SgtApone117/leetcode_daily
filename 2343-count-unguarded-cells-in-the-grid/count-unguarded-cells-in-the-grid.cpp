class Solution {
    private:
        void markGuarded(int row, int col, vector<vector<int>> &grid)
        {
            //top
            for(int i = row-1; i>= 0; --i)
            {
                if(grid[i][col] == -1 || grid[i][col] == -2)
                {
                    break;
                }
                grid[i][col] = 1;
            }
            //bottom
            for(int i = row+1; i < grid.size(); ++i)
            {
                if(grid[i][col] == -1 || grid[i][col] == -2)
                {
                    break;
                }
                grid[i][col] = 1;
            }
            //left
            for(int i = col-1; i >= 0; --i)
            {
                if(grid[row][i] == -1 || grid[row][i] == -2)
                {
                    break;
                }
                grid[row][i] = 1;
            }
            //right
            for(int i = col+1; i < grid[0].size(); ++i)
            {
                if(grid[row][i] == -1 || grid[row][i] == -2)
                {
                    break;
                }
                grid[row][i] = 1;
            }
        }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid (m, vector<int>(n, 0)); 

        for(vector<int> &guard : guards)
        {
            int u = guard[0];
            int v = guard[1];

            grid[u][v] = -1; //guard location
        }

        for(vector<int> &wall : walls)
        {
            int u = wall[0];
            int v = wall[1];

            grid[u][v] = -2; // wall location;
        }

        for(vector<int> &guard : guards)
        {
            int row = guard[0];
            int col = guard[1];

            markGuarded(row, col, grid);
        }

        int count = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};