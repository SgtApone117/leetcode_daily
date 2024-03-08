class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &num : nums)
            mp[num]++;
        int maxVal = INT_MIN;
        for(auto x : mp)
        {
            if(x.second > maxVal)
                maxVal = x.second;
        }   
        int sum = 0;
        for(auto x : mp)
        {
            if(x.second == maxVal)
                sum += x.second;
        }

        return sum; 
    }
};