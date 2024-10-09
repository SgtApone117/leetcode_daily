class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int openBracket = 0;
        int result = 0;

        for(char &ch : s)
        {
            if('(' == ch)
                openBracket++;
            else
                openBracket > 0 ? openBracket-- : result++;
        }
        return openBracket+result;
    }
};