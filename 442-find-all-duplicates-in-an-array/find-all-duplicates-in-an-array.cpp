class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        for(int &num : nums)
            mp[num]++;
        vector<int> res;
        for(auto &x : mp)
        {
            if(x.second / 2 == 1)
                res.push_back(x.first);
        }
        return res;
    }
};