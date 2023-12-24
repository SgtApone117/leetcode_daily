class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int ops = 0;
        for(int i = n-1; i>0; i--)
        {
            if(nums[i] == nums[i-1])
            {
                continue;
            }
            ops +=  n - i;
        }
        return ops;
    }
};