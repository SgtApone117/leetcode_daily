class Solution {
public:
    bool rotateString(string s, string goal) {
        string r = s;
        int n = r.length();
        for(int i = 1; i < n; i++)
        {
            r[i-1] = r[i];
        }
        r[n-1] = s[0];
        if(r == goal) return true; 
        while(r != s)
        {
            char first = r[0];
            for(int i = 1; i < n; i++)
            {
                r[i-1] = r[i];
            }
            r[n-1] = first;
            if(r == goal)
                return true;
        }
        return false;
    }
};