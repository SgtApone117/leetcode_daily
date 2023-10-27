class Solution {
public:
    int t[1001][1001];
    bool solve(string &s, int i, int j)
    {
            if(i >= j)
            {
                return true;
            }
            if(t[i][j] != -1)
            {
                return t[i][j];
            }
            if(s[i] == s[j])
            {
                return t[i][j] = solve(s,i+1, j-1);
            }

            return false;
    }
    string longestPalindrome(string s) {
        memset(t,-1,sizeof(t));
        int n = s.length();

        int maxLen = INT_MIN;
        int sp = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(solve(s,i,j))
                {
                    if(j-i+1 > maxLen)
                    {
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp,maxLen);
    }
};