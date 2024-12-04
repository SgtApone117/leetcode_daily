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
            if(str1[i] != str2[j])
            {
                char temp = (str1[i]%122 == 0 ? 97 : str1[i]%122+1);
                cout << temp << " ";
                if(temp == str2[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
                j++;
            }
        }

        if(j == m)
        {
            return true;
        }
        return false;
    }
};