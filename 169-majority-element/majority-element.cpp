class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &x : nums)
        {
            mp[x]++;
        }
        int maxVal = 0;
        for(auto itr : mp)
        {
            if(itr.second > nums.size() / 2)
            {
                maxVal = itr.first;
            }
        }
        return maxVal;
    }
};