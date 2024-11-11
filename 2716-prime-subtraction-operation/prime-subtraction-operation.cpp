class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes(1000,1);

        for(int i = 2; i*i < 1000; i++)
        {
            if(primes[i] == 1)
            {
                for(int j = i*i; j < 1000; j+= i)
                {
                    primes[j] = 0;
                }
            }
        }

        int n = nums.size();

        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                continue;
            }

            for(int p = 2; p < nums[i]; p++)
            {
                if(primes[p] == 0)
                {
                    continue;
                }

                if(nums[i]-p < nums[i+1])
                {
                    nums[i] -= p;
                    break;
                }
            }

            if(nums[i] >= nums[i+1])
            {
                return false;
            }
        }
        return true;
    }
};