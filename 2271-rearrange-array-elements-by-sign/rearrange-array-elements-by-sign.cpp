class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(0 , n/2);
        vector<int> neg(0 , n/2);
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }
        vector<int> res(n);
        for(int i = 0; i < n/2; i++)
        {
            res[2*i] = pos[i];
            res[2*i+1] = neg[i];
        }
        return res;
    }
};