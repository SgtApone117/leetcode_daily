class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {    
        vector<int> result;
        for(vector<int> &query : queries)
        {
            int xorResult = 0;
            for(int i = query[0]; i <= query[1]; i++)
            {
                xorResult ^= arr[i];
            }
            result.push_back(xorResult);
        }
        return result;
    }
};