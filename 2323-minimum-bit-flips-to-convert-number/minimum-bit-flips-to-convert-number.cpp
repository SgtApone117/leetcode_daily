class Solution {
public:
    int minBitFlips(int start, int goal) {
        int l = 0;
        int count = 0;
        while(l < 32)
        {
            if((start&(1 << l)) != (goal&(1 << l)))
                count++;
            l++;
        }
        return count;
    }
};