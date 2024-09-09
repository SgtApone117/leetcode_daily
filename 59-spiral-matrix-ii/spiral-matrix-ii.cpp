class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int dir = 0;

        int top   = 0;
        int down  = n-1;

        int left  = 0;
        int right = n-1;

        int counter = 1;

        while(top <= down && left <= right)
        {
            if(0 == dir)
            {
                for(int i = left; i <= right; i++)
                {
                    matrix[top][i] = counter++;
                }
                top++;
            }
            else if(1 == dir)
            {
                for(int i = top; i <= down; i++)
                {
                    matrix[i][right] = counter++;
                }
                right--;
            }
            else if(2 == dir)
            {
                for(int i = right; i >= left; i--)
                {
                    matrix[down][i] = counter++;
                }
                down--;
            }
            else
            {
                for(int i = down; i >= top; i--)
                {
                    matrix[i][left] = counter++;
                }
                left++;
            }

            dir += 1;

            if(4 == dir)
                dir = 0;
        }
        return matrix;
    }
};