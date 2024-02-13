class Solution {
public:
    bool findPalindrome(string& word)
    {
        int i = 0, j = word.length() - 1;
        while(j > i)
        {
            if(word[i] != word[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) 
    {
        int i,j,flag = 0;
        for(string &word : words)
        {
            if(findPalindrome(word))
                return word;
        }
        return "";
    }
};