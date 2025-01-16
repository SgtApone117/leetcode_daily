class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row_hash(10, vector<int>(10, 0));
        vector<vector<int>> col_hash(10, vector<int>(10, 0));
        vector<vector<int>> grid_hash(10, vector<int>(10, 0));

        for(int row = 0; row < 9; row++)
        {
            for(int col = 0; col < 9; col++)
            {
                if(board[row][col] == '.') continue;
                int val = board[row][col]-'0';
                if(row_hash[row][val]) return false;
                row_hash[row][val] = true;
                if(col_hash[col][val]) return false;
                col_hash[col][val] = true;
                int idx = (row/3*3+col/3);
                if(grid_hash[idx][val]) return false;
                grid_hash[idx][val] = true;
            }
        }
        return true;
    }
};