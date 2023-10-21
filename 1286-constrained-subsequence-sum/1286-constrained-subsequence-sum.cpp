class Solution {
public:
    typedef pair<int,int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> t(n);
        for(int i = 0; i < n; i++)
        {
            t[i] = nums[i];
        }
        priority_queue<P> pq;
        pq.push({t[0],0});
        int result = t[0];
        for(int i = 1; i < n; i++)
        {
            while(!pq.empty() && i - pq.top().second > k)
            {
                pq.pop();
            }
            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i],i});
            result = max(result,t[i]);
        }
        return result;
    }
};