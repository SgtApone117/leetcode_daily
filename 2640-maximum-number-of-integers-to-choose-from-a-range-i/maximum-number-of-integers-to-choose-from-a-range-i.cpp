class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < m; i++)
        {
            mp[banned[i]]++;
        }

        int i, sum, count;
        i = 1, sum = 0, count = 0;
        for(i; i <= n; i++)
        {
            if(mp.count(i) > 0)
            {
                continue;
            }
            else
            {
                sum += i;
                if(sum <= maxSum)
                {
                    count++;
                }
                else
                {
                    sum -= i;
                }
            }
        }
        return count;
    }
};