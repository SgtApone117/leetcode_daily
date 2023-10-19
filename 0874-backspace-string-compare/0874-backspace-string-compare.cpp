class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res1 = "";
        string res2 = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '#')
            {
                res1 += s[i];
            }
            else if(res1.length() > 0)
            {
                res1.pop_back();
            }
        }
        for(int j = 0; j < t.length(); j++)
        {
            if(t[j] != '#')
            {
                res2 += t[j];
            }
            else if(res2.length() > 0)
            {
                res2.pop_back();
            }
        }
        if(res1 != res2)
        {
            return false;
        }
        return true;
    }
};