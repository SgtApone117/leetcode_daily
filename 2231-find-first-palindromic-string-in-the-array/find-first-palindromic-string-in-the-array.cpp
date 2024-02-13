class Solution {
public:
    string firstPalindrome(vector<string>& words) 
    {
        int n = words.size();
        int i,j,flag = 0;
        for(string &word : words)
        {
            i = 0, j = word.length() - 1;
            flag = 1;
            if(word.length() == 1 || word.length() == 0)
                return word;
            if(word[i] == word[j])
            {
                while(j > i)
                {
                    if(word[i] != word[j])
                    {
                        flag = 0;
                        break;
                    }
                    i++;
                    j--;
                }
                if(flag == 1)
                    return word;
            }
        }
        return "";
    }
};