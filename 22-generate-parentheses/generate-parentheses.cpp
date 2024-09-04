class Solution {
public:
    void getParenthesis(int openBracket, int closeBracket, int n, string s, vector<string> &answer)
    {
        if(s.length() == 2*n)
        {
            answer.push_back(s);
            return;
        }
        if(openBracket < n)
        {
            getParenthesis(openBracket+1, closeBracket, n, s+"(", answer);
        }
        if(closeBracket < openBracket)
        {
            getParenthesis(openBracket, closeBracket+1, n, s+")", answer);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> answer;
        getParenthesis(0,0,n,"",answer);
        return answer;
    }
};