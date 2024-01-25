class Solution {
public:
    int m, n;
    int t[1001][1001];
    int solve(string& text1, string& text2, int i, int j)
    {
        if(i >= m || j >= n)
        {
            return 0;
        }
        if(t[i][j] != -1)
        {
            return t[i][j];
        }
        if(text1[i] == text2[j])
        {
            return t[i][j] = 1 + solve(text1, text2, i+1, j+1);
        }
        return t[i][j] = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length();
        n = text2.length();
        memset(t, -1, sizeof(t));
        return solve(text1,text2,0,0);
    }
};