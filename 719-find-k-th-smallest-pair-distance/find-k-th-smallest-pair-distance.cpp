class Solution {
public:
    int slidingWindow(vector<int>& nums, int d)
    {
        int i = 0;
        int j = 1;
        int pairCounts = 0;
        int n = nums.size();
        while(j < n)
        {
            while(nums[j]-nums[i] > d)
            {
                i++;
            }
            pairCounts += (j-i);
            j++;
        }
        return pairCounts;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int low = 0;
        int high = nums[n-1] - nums[0];
        int result = 0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;

            int countPair = slidingWindow(nums, mid);

            if(countPair < k)
            {
                low = mid+1;
            }
            else
            {
                result = mid;
                high = mid-1;
            }
        }
        return result;
    }
};