class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        string result = "";
        int i = 0, j = 0;
        for(int j = 0; j < m; j++)
        {
            if(s[i] == t[j])
            {
                result += t[j];
                i++;
            }
        }
        cout << result << endl;
        if(result == s)
            return true;
        return false;
    }
};