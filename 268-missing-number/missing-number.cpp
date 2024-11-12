class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++)
        {
            bool flag = false;
            for(int j = 0; j < n; j++)
            {
                if(i == nums[j])
                {
                    flag = true;
                }
            }
            if(!flag)
            {
                return i;
            }
        }
        return -1;
    }
};