class Solution {
public:

    void markGaurded(int row, int col, vector<vector<int>>& grid) {
        //UP
        for(int i = row-1; i >= 0; i--) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1; //Marking it as gaurded
        }

        //Down
        for(int i = row+1; i < grid.size(); i++) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1; //Marking it as gaurded
        }

        //left
        for(int j = col-1; j >= 0; j--) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1; //Marking it as gaurded
        }

        //right
        for(int j = col+1; j < grid[0].size(); j++) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1; //Marking it as gaurded
        }

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        //mark gaurds positions
        for(vector<int>& vec : guards) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2; //gaurd
        }

        //mark walls positions
        for(vector<int>& vec : walls) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3; //wall 
        }

        for(vector<int>& gaurd : guards) {
            int i = gaurd[0];
            int j = gaurd[1];
            markGaurded(i, j, grid); //four directions me check karo and mark karo gaurded
        }

        int count = 0;
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) { //ungaurded
                    count++;
                }
            }
        }

        return count;

    }
};