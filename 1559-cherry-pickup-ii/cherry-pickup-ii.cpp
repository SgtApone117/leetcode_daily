class Solution {
public:
    int row, col;
    int t[71][71][71];
    int solve(vector<vector<int>>& grid, int rRow, int r1_col, int r2_col)
    {
        if(rRow >= row)
        {
            return 0;
        }
        int cherry = grid[rRow][r1_col];
        if(r1_col != r2_col)
        {
            cherry += grid[rRow][r2_col];
        }

        if(t[rRow][r1_col][r2_col] != -1)
        {
            return t[rRow][r1_col][r2_col];
        }

        int ans = 0;
        for(int r1 = -1; r1 <= 1; r1++)
        {
            for(int r2 = -1; r2 <= 1; r2++)
            {
                int newRow = rRow+1;
                int newR1Col = r1_col+r1;
                int newR2Col = r2_col+r2;
                if((newR1Col >= 0 && newR1Col < col) && (newR2Col >= 0 && newR2Col < col))
                {
                    ans = max(ans, solve(grid, newRow, newR1Col, newR2Col));
                }
            }
        }
        return t[rRow][r1_col][r2_col] = cherry + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        memset(t, - 1, sizeof(t));
        return solve(grid, 0, 0, col-1);
    }
};