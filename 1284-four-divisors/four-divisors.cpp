class Solution {
public:
    bool isPrime(int n)
    {
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums)
        {
            int p = round(cbrt(num));
            if(p*p*p == num && isPrime(p))
            {
                totalSum = totalSum + 1 + num + p + (p * p);
                continue;
            }

            for(int i = 2; i * i <= num; i++)
            {
                if(num % i == 0)
                {
                    int j = num / i;
                    if(i != j && isPrime(i) && isPrime(j))
                    {
                        totalSum = totalSum + i + j + 1 + num;
                    }
                    break;
                }
            }
        }
        return totalSum;
    }
};