class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> hash(256, -1);
        int l = 0, r = 0;
        int maxLen = 0;
        int n = s.length();
        while(r < n)
        {
            if(hash[s[r]] != -1)
            {
                //cout << hash[s[r]] << endl;
                if(hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};