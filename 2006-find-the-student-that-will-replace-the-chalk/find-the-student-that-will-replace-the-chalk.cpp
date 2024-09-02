class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalk = 0;

        for(int& chalkReq : chalk)
        {
            totalChalk += chalkReq;
        }

        int remainingChalk = k%totalChalk;

        for(int i = 0; i < n; i++)
        {
            if(remainingChalk < chalk[i])
                return i;
            remainingChalk -= chalk[i];
        }
        return -1;
    }
};