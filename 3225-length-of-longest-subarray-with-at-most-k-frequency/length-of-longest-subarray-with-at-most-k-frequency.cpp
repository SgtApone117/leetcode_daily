class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int> ump;
        int maxRes = INT_MIN;
        int i = 0, j = 0;
        while(j < n)
        {
            ump[nums[j]]++;
            while(i < j && ump[nums[j]] > k)
            {
                ump[nums[i]]--;
                i++;
            }
            maxRes = max(maxRes, j-i+1);
            j++;
        }
        return maxRes;
    }
};