class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int currSum = 0;
        mp[currSum]++;
        int result = 0;
        for(int &num : nums)
        {
            currSum += num;
            if(mp.find(currSum - goal) != mp.end())
            {
                result += mp[currSum - goal];
            }
            mp[currSum]++;
        }
        return result;
    }
};