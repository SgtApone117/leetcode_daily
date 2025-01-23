class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    bool can_comm = false;
                    for(int k = 0; k < col; k++)
                    {
                        if(k != j && grid[i][k] == 1)
                        {
                            can_comm = true;
                            break;
                        }
                    }
                    if(can_comm == true)
                    {
                        count++;
                    }
                    else
                    {
                        for(int k = 0; k < row; k++)
                        {
                            if(k != i && grid[k][j] == 1)
                            {
                                can_comm = true;
                                break;
                            }
                        }
                        if(can_comm == true) count++;;
                    }
                    
                }
            }
        }
        return count;
    }
};