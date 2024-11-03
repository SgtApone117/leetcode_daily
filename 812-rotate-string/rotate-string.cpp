class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m) return false;

        int i = 0;
        while(i < n)
        {
            char first = s[0];
            for(int j = 0; j < n; j++)
            {
                s[j] = s[j+1];
            }
            s[n-1] = first;
            if(s == goal) return true;
            i++;
        }
        return false;
    }
};