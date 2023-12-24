class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int start_with_0 = 0;

        for(int i = 0; i < n; i++)
        {
            if(0 == i % 2)
            {
                if('1' == s[i])
                {
                    start_with_0++;
                }
            }
            else
            {
                if('0' == s[i])
                {
                    start_with_0++;
                }
            }
        }
        return min(n - start_with_0, start_with_0);
    }
};