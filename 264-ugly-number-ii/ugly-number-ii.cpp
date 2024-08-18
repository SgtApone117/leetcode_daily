class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int> arr(n+1);

        arr[1] = 1;
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        for(int i = 2; i <= n; i++)
        {
            int i2ndUgly = arr[i2] * 2;
            int i3rdUgly = arr[i3] * 3;
            int i5thUgly = arr[i5] * 5;

            int minUgly = min({i2ndUgly, i3rdUgly, i5thUgly});
            arr[i] = minUgly;
            if(minUgly == i5thUgly)
                i5++;
            if(minUgly == i3rdUgly)
                i3++;
            if(minUgly == i2ndUgly)
            {
                i2++;
            }
        }  
        return arr[n];
    }
};