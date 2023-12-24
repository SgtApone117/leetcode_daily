class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);

        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 1)
                {
                    onesRow[row]++;
                    onesCol[col]++;
                }
            }
        }

        vector<vector<int>> diff(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int onesRowi = onesRow[i];
                int onesColj = onesCol[j];
                int zerosRowi = n - onesRowi;
                int zerosColj = m - onesColj;
                diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj; 
            }
        }
        return diff;
    }
};