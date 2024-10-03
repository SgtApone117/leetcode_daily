class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        int n = word1.length();
        int m = word2.length();

        string res = "";

        while(i < n || j < m)
        {
            if(i < n)
            {
                res += word1[i];
                i++;
            }
            if(j < m)
            {
                res += word2[j];
                j++;
            }
        }
        return res;
    }
};