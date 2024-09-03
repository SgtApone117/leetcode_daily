class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;
        for(int j = 0; j < m; j++)
        {
            if(s[i] == t[j])
            {
                i++;
            }
        }
        cout << i << endl;
        if(i == n)
            return true;
        return false;
    }
};