class Solution {
public:
    const int UNVISITED = -1000000001;
    int solve(vector<int>& nums1, vector<int>& nums2, int m, int n,int i, int j,int memo[501][501])
    {
        if(i == m || j == n)
        {
            return INT_MIN;
        }

        if(memo[i][j] != UNVISITED)
        {
            return memo[i][j];
        }

        int takePairsAndContinue = nums1[i]*nums2[j] + max(0, solve(nums1, nums2, m, n, i+1, j+1, memo));;
        int skipA = solve(nums1, nums2, m, n, i+1, j, memo);
        int skipB = solve(nums1, nums2, m, n, i, j+1, memo);

        return memo[i][j] = max({takePairsAndContinue, skipA, skipB});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int memo[501][501];
        for(int i = 0; i < 501; i++)
        {
            for(int j = 0; j < 501; j++)
            {
                memo[i][j] = UNVISITED;
            }
        }
        return solve(nums1, nums2, nums1.size(), nums2.size(), 0,0,memo);
    }
};