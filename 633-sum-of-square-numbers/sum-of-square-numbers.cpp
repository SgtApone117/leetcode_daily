class Solution {
public:
    bool judgeSquareSum(int n) {
        for(int i = 2; i*i <= n; i++)
        {
            int count = 0;
            if(n % i == 0)
            {
                while(n % i == 0)
                {
                    count++;
                     n /= i;
                }

                if(i % 4 == 3 && count % 2 != 0)
                {
                    return false;
                }
            }
        }
        return n % 4 != 3; 
    }
    
};