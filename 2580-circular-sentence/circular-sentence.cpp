class Solution {
public:
    bool isCircularSentence(string s) {
        char first_char, second_char;
        int n = s.length();
        char first_letter = s[0];
        for(int i = 0; i < n; i++)
        {
            if(s[i+1] == ' ')
            {
                first_char  = s[i];
                second_char =  s[i+2];
                if(first_char != second_char)
                    return false;
            }
        }
        if(s[0] != s[n-1])
            return false;
        return true;
    }
};