class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.length();
        int maxVal = num;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    swap(numStr[i], numStr[j]);
                    if(stoi(numStr) > maxVal)
                        maxVal = stoi(numStr);
                    swap(numStr[i], numStr[j]);
                }
            }
        }
        return maxVal;
    }
};