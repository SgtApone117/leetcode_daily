class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        int n = pref.size();
        res.emplace_back(pref[0]);
        for(int i = 0; i < n - 1; i++)
        {
            res.emplace_back(pref[i]^pref[i+1]);
        }
        return res;
    }
};