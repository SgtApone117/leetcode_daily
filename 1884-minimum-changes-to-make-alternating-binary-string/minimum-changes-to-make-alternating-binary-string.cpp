class Solution {
public:
    int minOperations(string s) {
        int start_with_one = 0, start_with_zero = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(0 == i % 2)
            {
                if('0' == s[i])
                {
                    start_with_one++;
                }
                else
                {
                    start_with_zero++;
                }
            }
            else
            {
                if('1' == s[i])
                {
                    start_with_one++;
                }
                else
                {
                    start_with_zero++;
                }
            }
        }
        return min(start_with_one, start_with_zero);
    }
};