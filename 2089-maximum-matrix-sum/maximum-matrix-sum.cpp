class Solution {
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count_negve = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int get_min = INT_MAX;
        
        ll total_sum = 0;
        for(int row = 0; row < m; ++row)
        {
            int *p = &matrix[row][0];
            for(int col = 0; col < n; ++col)
            {
                get_min = min(get_min, abs(*(p + col)));
                total_sum += abs(*(p + col));
                if(*(p + col) < 0)
                {                    
                    count_negve++;
                }
            }
        }
        if(!(count_negve&1))
        {
            return total_sum;
        }
        else
        {
            return total_sum-(2*get_min);
        }
        return 0;
    }
};