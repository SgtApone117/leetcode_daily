class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (nums.size() + 1) / 2;
        int sumOfArray = accumulate(nums.begin(), nums.end(), 0);
        return abs((sum - sumOfArray));
    }
};