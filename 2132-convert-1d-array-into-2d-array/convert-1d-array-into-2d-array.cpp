class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size())
            return {};
        vector<vector<int>> res(m, vector<int>(n));
        int x = 0;
        for(int i = 0; i < original.size(); i++)
        {
            res[i/n][i%n]=original[i];
        }
        return res;
    }
};