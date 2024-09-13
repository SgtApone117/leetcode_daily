class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {    
        int n = arr.size();
        vector<int> prefixArr(n+1,0);
        for(int i = 0; i < n; i++)
        {
            prefixArr[i+1] = prefixArr[i]^arr[i];
        }

        vector<int> result;

        for(vector<int> &query : queries)
        {
            result.push_back(prefixArr[query[1]+1] ^ prefixArr[query[0]]);
        }
        return result;
    }
};