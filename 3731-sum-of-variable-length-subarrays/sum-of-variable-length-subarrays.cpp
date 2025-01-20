class Solution {
public:
    int subarraySum(vector<int>& nums) {
        
        int amount = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int start = max(0, i-nums[i]);
            for(int j = start; j <= i; j++)
            {
                amount += nums[j];
            }
        }
        return amount;
    }
};