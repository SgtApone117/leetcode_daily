class Solution {
public:
    int t[101];
    int solve(int i, string& s, int& n)
    {
        if(-1 != t[i])
        {
            return t[i];
        }
        if(n == i)
        {
            return t[i] = 1;
        }
        if('0' == s[i])
        {
            return t[i] = 0;
        }

        int result = 0;

        result = solve(i+1, s, n);
        if(i+1 < n)
        {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
            {
                result += solve(i+2, s, n);
            }
        }
        return t[i] = result;
    }
    int numDecodings(string s) {
        int n = s.length();
        memset(t, -1 ,sizeof(t));
        return solve(0,s,n);
    }
};