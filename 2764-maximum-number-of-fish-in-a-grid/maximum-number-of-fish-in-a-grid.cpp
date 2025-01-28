class Solution {
public:
    int m,n;
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int bfs(int i, int j, vector<vector<int>>& grid)
    {
        queue<pair<int,int>> que;
        que.push({i,j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;

        while(!que.empty())
        {
            i = que.front().first;
            j = que.front().second;
            que.pop();

            for(auto &dir : directions)
            {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 and j_ >= 0 and i_ < m and j_ < n and grid[i_][j_] > 0)
                {
                    que.push({i_,j_});
                    fishCount += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }
        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] > 0)
                {
                    maxFish = max(maxFish, bfs(i,j,grid));
                }
            }
        }
        return maxFish;
    }
};