class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int mRow = matrix.size();
        int mCol = matrix[0].size();

        int maxArea = 0;

        for(int row = 0; row < mRow; row++)
        {
            for(int col = 0; col < mCol; col++)
            {
                if(matrix[row][col] == 1 && row > 0)
                {
                    matrix[row][col] += matrix[row-1][col];
                }
            }
            vector<int> heights = matrix[row];
            sort(begin(heights), end(heights), greater<int>());

            for(int i = 0; i < mCol; i++)
            {
                int base = i+1;
                int height = heights[i];

                maxArea = max(maxArea, base*height);
            }
        }
        return maxArea;
    }
};