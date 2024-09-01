class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();

        if(len > m*n || len < m*n)
            return {};
        vector<vector<int>> res(m);
        int x = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res[i].push_back(original[x]);
                x++;
            }
        }
        return res;
    }
};