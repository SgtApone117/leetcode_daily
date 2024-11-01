class Solution {
public:
    string makeFancyString(string s) {
        char currChar = s[0];
        int currCount = 1;
        string res = "";
        res += currChar;
        for(int i = 1; i < s.length(); i++)
        {
            currCount += 1;
            if(s[i] != currChar)
            {
                currChar = s[i];
                currCount = 1; 
                res += s[i];
            }
            else if(currCount >= 3)
            {
                continue;
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};