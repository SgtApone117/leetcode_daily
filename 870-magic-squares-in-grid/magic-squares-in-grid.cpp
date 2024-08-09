class Solution {
public:
    bool isMagicGrid(vector<vector<int>>& grid, int r, int c)
    {
        unordered_set<int> st; // use set to put unique numbers from 1 to 9;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int nums = grid[r+i][c+j]; // to get the current values from next 3x3 matrix
                if(nums < 1 || nums > 9 || st.count(nums))
                    return false;
                else
                    st.insert(nums);
            }
        }

        int tot_sum = grid[r][c] + grid[r][c+1] + grid[r][c+2]; // condition is all row,column and diagonal(both) should be same so take any of the rows sum;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != tot_sum) // all row sums
                    return false;
                if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != tot_sum) // all column sum
                    return false;
            }
        }

        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != tot_sum) // diagonal sum
            return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != tot_sum) // anti diagonal sum
            return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.size();

        int count = 0;

        for(int i = 0; i <= rows - 3; i++) // subtract 3 two get maximum extent of 3x3 rows we can get
        {
            for(int j = 0; j <= cols - 3; j++) // subtract 3 two get maximum extent of 3x3 columns we can get
            {
                if(isMagicGrid(grid,i,j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};