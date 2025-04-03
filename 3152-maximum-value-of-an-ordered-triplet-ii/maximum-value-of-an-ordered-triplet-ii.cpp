class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = (int)nums.size();
        vector<int> prefix_max(n, 0);  
        int mx = nums[0];
        for(int i = 1; i < n; i++)
        {
            prefix_max[i] = mx;
            mx = max(mx, nums[i]);
        }
        vector<int> suffix_max(n, 0);
        mx = nums[n-1];
        for(int i = n - 2; i >= 0; i--)
        {
            suffix_max[i] = mx;
            mx = max(mx, nums[i]);
        }
        long long sum = 0;
        for(int i = 0; i < n - 1; i++)
        {
            long long temp = (prefix_max[i] - (1LL*nums[i])) * (1LL*suffix_max[i]);
            if(temp > sum)
                sum = temp;
        }
        return sum;
    }
};