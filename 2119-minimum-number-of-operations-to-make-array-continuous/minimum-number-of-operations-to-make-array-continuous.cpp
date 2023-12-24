class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = (int)nums.size(), i = 0, j = 0, ans = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        for(int k = (int)nums.size(); j < k; ++j)
        {
            while(nums[i] + n <= nums[j]) ++i;
            ans = max(ans, j-i+1);
        }
        return n - ans;
    }
};