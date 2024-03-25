class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> res;
        sort(begin(nums), end(nums));
        for(int i = 0; i < nums.size(); i++)
        {
            if(i+1 < nums.size() && nums[i] == nums[i+1])
            {
                res.push_back(nums[i]);
            }
            cout << i << endl;
        }
        return res;
    }
};