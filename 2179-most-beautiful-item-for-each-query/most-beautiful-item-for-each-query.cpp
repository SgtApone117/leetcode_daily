class Solution {
public:
    int binarySearch(int query, vector<vector<int>>& items)
    {
        int low,high,mid,maxBeauty;
        low = 0;
        high = items.size()-1;
        maxBeauty = 0;
        while(low <= high)
        {
            mid = ((low+high)>>1);
            if(items[mid][0] > query)
            {
                high = mid-1;
            }
            else
            {
                maxBeauty = max(maxBeauty, items[mid][1]);
                low = mid + 1;
            }
        }
        return maxBeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        vector<int> result(m);
        sort(begin(items), end(items));

        int maxBeautySeen = items[0][1];
        for(int i = 0; i < n; i++)
        {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }

        for(int i = 0; i < m; i++)
        {
            int query = queries[i];
            result[i] = binarySearch(query, items);
        }
        return result;
    }
};