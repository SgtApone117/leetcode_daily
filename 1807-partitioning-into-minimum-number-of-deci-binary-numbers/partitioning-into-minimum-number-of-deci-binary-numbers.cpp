class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for(char ch : n)
        {
            maxDigit = max(maxDigit, (ch-'0'));
        }
        return maxDigit;
    }
};