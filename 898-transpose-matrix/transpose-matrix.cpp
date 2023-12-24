class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size()));
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};