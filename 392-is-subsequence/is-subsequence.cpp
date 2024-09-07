class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;
        for(int j = 0; j < m; j++)
        {
            if(i == n)
                break;
            if(s[i] == t[j])
            {
                i++;
            }
        }
        return (i == n);
    }
};