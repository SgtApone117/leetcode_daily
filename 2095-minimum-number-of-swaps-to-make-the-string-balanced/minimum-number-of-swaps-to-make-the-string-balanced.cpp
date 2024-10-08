class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int start = 0;
        int end = 0;
        for(char &ch : s)
        {
            if('[' == ch) end++;
            else if(end) end--;
            else start++;
        }
        return start/2 + start%2;
    }
};