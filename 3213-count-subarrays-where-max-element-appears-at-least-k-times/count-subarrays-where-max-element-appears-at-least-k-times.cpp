class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element (begin(nums), end(nums));
        int i = 0, j = 0;
        int n = nums.size();
        long long res = 0;
        int countMax = 0;
        while(j < n)
        {
            if(nums[j] == maxElement)
            {
                countMax++;
            }
            while(countMax >= k)
            {
                res += n-j;
                if(nums[i] == maxElement)
                {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};