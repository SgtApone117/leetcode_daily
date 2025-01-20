class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int max_diff = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int dist1 = abs(nums[abs((i-1)%n)]-nums[i]);
            int dist = abs(nums[abs((i+1)%n)] - nums[i]);
            max_diff = max(max_diff, max(dist,dist1));
        }
        return max_diff;
    }
};