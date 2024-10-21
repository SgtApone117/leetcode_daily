class Solution {
public:
    void solve(string& s, int start, unordered_map<string, int> &mp, int& maxCount, int currCount)
    {
        if(start >= s.length())
        {
            maxCount = max(maxCount, currCount);
            return;
        }

        for(int j = start; j < s.length(); j++)
        {
            string str = s.substr(start, j-start+1);
            if(mp.find(str) == mp.end())
            {
                mp[str] = 1;
                solve(s, j+1, mp, maxCount, currCount+1);
                mp.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_map<string, int> mp;
        int i = 0;
        int maxCount  = 0;
        int currCount = 0;

        solve(s, i, mp, maxCount, currCount);
        return maxCount;
    }
};