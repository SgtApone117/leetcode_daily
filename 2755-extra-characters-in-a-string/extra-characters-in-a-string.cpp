class Solution {
public:
int t[51];
    int solve(int idx, string& s, unordered_set<string>& st, int& n)
    {
        if(idx >= n) //out of bound or end of string
            return 0;
        if(t[idx] != -1)
            return t[idx];
        int result = 1 + solve(idx+1, s, st, n); //if we take the character as extra
        for(int j = idx; j < n; j++)
        {
            string curr = s.substr(idx, j-idx+1);
            if(st.count(curr))
            {
                result = min(result, solve(j+1, s, st, n)); // if we choose to consider this string may occur in set
            }
        }
        return t[idx] = result;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        unordered_set<string> st(begin(dict), end(dict));

        return solve(0, s, st, n);
    }
};