class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        int sum = accumulate(begin(nums), end(nums), 0);
        int prefixSum = 0;

        for(int i = 0; i < n; i++)
        {
            int leftSum = prefixSum;
            int rightSum = sum - prefixSum - nums[i];

            result[i] = (nums[i] * i) - leftSum + rightSum - (nums[i]* (n-i-1));
            prefixSum += nums[i];
        }
        return result;
    }
};