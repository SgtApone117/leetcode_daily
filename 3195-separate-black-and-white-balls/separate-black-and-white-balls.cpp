class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long count = 0;

        for(char ch : s)
        {
            if('1' == ch)
                count++;
            else
                ans += count;
        }
        return ans;
    }
};