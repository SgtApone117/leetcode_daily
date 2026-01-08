class Solution {
public:
    using LL = long long;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // first count the number of negative numbers 
        // if they are even just return the sum of all
        // if they have odd then get the minimum number multiply by 2 as the change in sum will be always 2 because change is always = finalvalue - initial value 
        // in this case we are inverting or flipping the numbers so suppose first x = -7 and then x = 7 we get change = 7+7 = 2 * 7
        LL minNumber = INT_MAX;
        LL total_sum = 0;
        LL total_negative_numbers = 0;
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                LL current_element = matrix[i][j];
                if(matrix[i][j] < 0)
                {
                    total_negative_numbers++;
                    current_element = -1 * current_element;
                }
                minNumber = min(minNumber, current_element);
                total_sum = total_sum + current_element;

            }
        }
        if(total_negative_numbers % 2 == 0)
        {
            return total_sum;
        }
        return (total_sum - 2 * (minNumber));
    }
};