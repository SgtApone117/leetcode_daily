class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        int count = 0;
        int n = s.size();
        char ch = s[0];
        for(char &c : s)
        {
            if(c == ch)
            {
                count++;
                continue;
            }
            if(count % 2 == 0)
            {
                count = 1;
            }
            else
            {
                count = 0;
                changes++;
            }
            ch = c;
        }
        return changes;
    }
};