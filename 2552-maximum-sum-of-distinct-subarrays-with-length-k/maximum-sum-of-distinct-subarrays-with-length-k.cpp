class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        long long sum, max_sum, curr_sum;
        sum = 0, max_sum = 0;
        for(int i = 0; i < k; ++i)
        {
            mp[nums[i]]++;
            sum += nums[i];
        }
        curr_sum = sum;
        if(mp.size() == k)
        {
            max_sum = max(max_sum, curr_sum);
        }
        for(int i = k; i < n; i++)
        {
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0)
            {
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            curr_sum += nums[i] - nums[i-k];
            if(mp.size() == k)
            {
                max_sum = max(max_sum, curr_sum);
            }
        }
        return max_sum;
    }
};