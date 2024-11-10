class Solution {
public:
    void updateBits(int number, vector<int> &bitVec, int val)
    {
        for(int i = 0; i < 32; i++)
        {
            if((number >> i) & 1)
            {
                bitVec[i] += val;
            }
        }
    }

    int isDecimal(vector<int> &vec)
    {
        int num = 0;
        for(int i = 0; i < 32; i++)
        {
            if(vec[i] > 0)
            {
                num |= (1 << i);
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitVec(32, 0);
        int i, j;
        i = 0, j = 0;
        int result = INT_MAX;
        while(j < n)
        {
            updateBits(nums[j], bitVec, 1);
            while(i <= j && isDecimal(bitVec) >= k)
            {
                result = min(result, j-i+1);
                updateBits(nums[i], bitVec, -1);
                i++;
            }
            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};