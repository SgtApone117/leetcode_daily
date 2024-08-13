class Solution {
public:
    void solve(int idx, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp)
    {
        if(idx == candidates.size())
        {
            if(target == 0)
            {
                result.push_back(temp);
            }
            return;
        }

        if(candidates[idx] <= target)
        {
            temp.push_back(candidates[idx]);
            solve(idx, target - candidates[idx], candidates, result, temp);
            temp.pop_back();
        }
        solve(idx+1, target, candidates, result, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, target, candidates, result, temp);
        return result;
    }
};