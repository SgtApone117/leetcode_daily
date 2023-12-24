class Solution {
public:
    string reverseWords(string s) 
    {
        string word;
        stringstream str(s);
        string st;
        while(str >> word)
        {
            reverse(word.begin(),word.end());
            st += word + " ";
        }
        return st.substr(0, st.length() - 1);
    }
};