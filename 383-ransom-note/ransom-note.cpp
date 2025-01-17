class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        //if(n != m) return false;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int i,j;
        int temp = n;
        i = 0, j = 0;
        while(i < n &&  j < m && temp > 0)
        {
            if(ransomNote[i] == magazine[j])
            {
                i++;
                j++;
                temp--;
            }
            else
            {
                j++;
            }
        }
        if(temp > 0) return false;
        return true;
    }
};