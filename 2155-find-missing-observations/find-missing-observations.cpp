class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
        int missing_numbers = mean*(n+rolls.size()) - sum_m;
        if(missing_numbers < n || missing_numbers > 6*n)
            return {};
        vector<int> result;
        while(n)
        {
            int dice = min(6,missing_numbers-n+1);
            result.push_back(dice);
            missing_numbers -= dice;
            n--;
        }
        return result;
    }
};