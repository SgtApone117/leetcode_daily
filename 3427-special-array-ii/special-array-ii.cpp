class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<bool> ans;
        int p = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] % 2 != nums[i] % 2)
            {
                prefix[i] = p;
            }
            else
            {
                p++;
                prefix[i] = p;
            }
        }
        for(int i = 0; i < queries.size(); i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            
            if(prefix[a] == prefix[b])
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};