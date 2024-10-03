class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int SUM = 0;
        for(int &num : nums)
            SUM = (SUM + num)%p;
        int target = SUM % p;
        if(0 == target) return 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int curr = 0;
        int result = n;
        for(int i = 0; i < n; i++)
        {
            curr = (curr + nums[i])%p;

            int rem = (curr - target + p) % p;
            if(mp.find(rem) != mp.end())
            {
                result = min(result, i - mp[rem]);
            }
            mp[curr] = i;
        }
        return result == n ? -1 : result;
    }
};