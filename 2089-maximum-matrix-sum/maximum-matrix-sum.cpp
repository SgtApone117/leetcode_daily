class Solution {
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count_negve = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int get_min = INT_MAX;
        int* p[m];
        for (int i = 0; i < m; ++i) {
        p[i] = matrix[i].data();
    }
        ll total_sum = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                get_min = min(get_min, abs(*(*(p + i) + j)));
                total_sum += abs(*(*(p + i) + j));
                if(*(*(p + i) + j) < 0)
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