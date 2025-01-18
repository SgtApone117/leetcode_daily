class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int calc = target-nums[i];
            if(mp.find(calc) != mp.end())
            {
                return {mp[calc], i};
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};