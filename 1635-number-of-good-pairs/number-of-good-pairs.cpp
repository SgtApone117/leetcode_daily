class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        unordered_map<int,int> ump;
        int count = 0;
        for(int num : nums)
            count += ump[num]++;
        return count;
    }
};