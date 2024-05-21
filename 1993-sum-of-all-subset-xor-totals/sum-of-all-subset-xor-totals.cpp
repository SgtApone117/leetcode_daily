class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subSets)
    {
        if(i == nums.size())
        {
            subSets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        solve(nums, i+1, currSubset, subSets);
        currSubset.pop_back();
        solve(nums, i+1, currSubset, subSets);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subSets;
        vector<int> currSubset;

        solve(nums, 0, currSubset, subSets);

        int result = 0;
        for(vector<int> &subSet : subSets)
        {
            int Xor = 0;
            for(int &num : subSet)
            {
                Xor ^= num;
            }
            result += Xor;
        }
        return result;
    }
};