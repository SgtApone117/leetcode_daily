class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        int MOD = 1e9+7;
        vector<long long> newArray;
        for(int i = 0; i < n; i++)
        {
            long long sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += nums[j];
                newArray.push_back(sum);
            }
        }

        sort(newArray.begin(), newArray.end());
        long long newSum = 0;
        for(int i = left-1; i < right; i++)
        {
            newSum += newArray[i];
        }
        return newSum % MOD;
    }
};