class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        unordered_map<int,long long> mp;

        mp[arr[0]] = 1;
        for(int i = 1; i < n; i++)
        {
            int root = arr[i];
            mp[root] = 1;

            for(int j = 0; j < i; j++)
            {
                int LC = arr[j];
                if(root%LC == 0 && mp.find(arr[i]/LC) != mp.end())
                {
                    mp[root] += mp[LC] * mp[arr[i]/LC];
                }
            }
        }

        long result = 0;
        for(auto &it: mp)
        {
            result = (result + it.second) % MOD;
        }
        return result;
    }
};