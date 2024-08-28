class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool checkIfIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j)
    {
        int n = grid1.size();
        int m = grid1[0].size();

        bool result = true;
        queue<pair<int,int>> que;
        que.push({i,j});
        grid2[i][j] = -1;

        while(!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1)
                result = false;
            for(vector<int>& dir : directions)
            {
                int newX = x+dir[0];
                int newY = y+dir[1];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid2[newX][newY] == 1)
                {
                    grid2[newX][newY] = -1;
                    que.push({newX, newY});
                }
            }
        }
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