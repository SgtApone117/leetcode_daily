class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int prevDeviceCount = 0;
        int result = 0;

        for(int i = 0; i < n; i++)
        {
            int currDeviceCount = 0;
            for(char &ch : bank[i])
            {
                if('1' == ch)
                {
                    currDeviceCount++;
                }
            }
            result += (prevDeviceCount * currDeviceCount);

            if(0 != currDeviceCount)
            {
                prevDeviceCount = currDeviceCount;
            }
        }
        return result;
    }
};