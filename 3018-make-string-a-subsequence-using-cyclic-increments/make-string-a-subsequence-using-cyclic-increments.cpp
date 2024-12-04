class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i,j; // i points to str1 and j points to str2
        i = 0, j = 0;
        int n = str1.length();
        int m = str2.length();
        if(n < m) // if str1 length is less than str2, str2 cannot be subsequence of str1
        {
            return false;
        }

        while(i < n && j < m)
        {
            if(str1[i] == str2[j] ||
               (((str1[i]-'a'+1)%26)+'a') == str2[j])
            {
                j++;
            }
            ++i;
        }

        if(j == m)
        {
            return true;
        }
        return false;
    }
};