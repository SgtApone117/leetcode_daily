class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, int currSum)
    {
        if(idx == nums.size())
        {
            if(target == currSum) return 1;
            else return 0;
        }
        int plus = solve(nums, target, idx+1, currSum+nums[idx]);
        int minus = solve(nums, target, idx+1, currSum-nums[idx]);
        return plus+minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};