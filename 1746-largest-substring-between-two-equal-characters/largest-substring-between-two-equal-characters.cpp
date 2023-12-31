class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();

        int result = -1;

        for(int i = 0; i <= n-2; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    result = max(result, j-i-1);
                }
            }
        }
        return result;
    }
};